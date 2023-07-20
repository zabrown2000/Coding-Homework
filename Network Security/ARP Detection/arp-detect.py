from scapy.all import ARP, sniff
import time
import os
import multiprocessing
from multiprocessing import Process, Manager


def DetectInvalidMac(packet, arp_spoof_flag):
    # Dictionary to store IP-MAC mappings 
    ip_mac_mappings = {
        "10.0.0.46" : "08:00:27:b1:9d:67", 
        "10.0.0.138" : "00:b8:c2:a3:f2:cc",
        "10.0.0.47" : "08:00:27:59:8d:69"
    }
    spoof_flag = False

    # Only looking in response/is-at packets
    if ARP in packet and packet[ARP].op == 2:  
        src_ip = packet[ARP].psrc
        src_mac = packet[ARP].hwsrc

        if src_ip in ip_mac_mappings:
            # Check if source MAC address matches the stored MAC address
            if src_mac != ip_mac_mappings[src_ip]:
                spoof_flag = True
        # Update the dictionary with the current MAC address 
        ip_mac_mappings[src_ip] = src_mac

    arp_spoof_flag.value = spoof_flag



def GetArpCache():
    arp_cache = []
    # getting the output of the arp table and parsing it to get the ip-mac pairs
    output = os.popen('arp -a').read()
    lines = output.splitlines()
    for line in lines:
        parts = line.split()
        if len(parts) >= 4:
            ip = parts[1].strip('()')
            mac = parts[3]
            arp_entry = (ip, mac)
            arp_cache.append(arp_entry)
    return arp_cache

def DetectArpCacheChanges(arp_spoof_flag): 
    # Store the initial ARP cache
    initial_arp_cache = GetArpCache()

    # Periodically check for changes in ARP cache
    while True:
        current_arp_cache = GetArpCache()
        if current_arp_cache != initial_arp_cache:
            arp_spoof_flag.value = True
            # Reset the ARP cache
            initial_arp_cache = current_arp_cache
        time.sleep(3)  # Sleep for 3 seconds before checking again


if __name__ == "__main__":
    # Create a manager object to share state between processes
    manager = Manager()
    # flags to keep track of the different indicators
    arp_mac_flag = manager.Value('b', False)
    arp_cache_flag = manager.Value('b', False)

    # Start the ARP cache change detection process
    arp_cache_process = Process(target=DetectArpCacheChanges, args=(arp_cache_flag,))
    arp_cache_process.start()

    # Start capturing ARP packets and send each packet to be processed using prn to direct each packet to DetectInvalidMac
    capture_process = Process(target=sniff, kwargs={"filter": "arp", "prn": lambda packet: DetectInvalidMac(packet, arp_mac_flag), "store": 0, "iface": 'eth0'})
    capture_process.start()

    while True:
        # once both indicator flags are turned on the warning is activated
        if arp_mac_flag.value and arp_cache_flag.value:
            print("WARNING: ARP SPOOFING DETECTED")
            # reseting the flags so we can continuously check for spoofing
            arp_mac_flag.value = False
            arp_cache_flag.value = False

            # protection method - permanetly bind the correct ip-mac pairs in the arp table
            os.system("sudo arp -i eth0 -s 10.0.0.46 08:00:27:b1:9d:67")
            os.system("sudo arp -i eth0 -s 10.0.0.138 00:b8:c2:a3:f2:cc")
            os.system("sudo arp -i eth0 -s 10.0.0.47 08:00:27:59:8d:69")
        time.sleep(1)

    # Wait for both processes to finish
    capture_process.join()
    arp_cache_process.join()

