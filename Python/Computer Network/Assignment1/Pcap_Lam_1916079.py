import pyshark
import sys

def calculate_data_rate(pcap_file_path):
    capture = pyshark.FileCapture(pcap_file_path, display_filter='ip.src == 104.198.203.13 && tcp.port == 443')

    total_bytes = 0
    first_packet_time = None
    last_packet_time = None

    for packet in capture:
        total_bytes += int(packet.length)
        packet_time = float(packet.sniff_time.timestamp())
        if first_packet_time is None:
            first_packet_time = packet_time
        last_packet_time = packet_time

    capture.close()

    if first_packet_time and last_packet_time:
        time_interval = last_packet_time - first_packet_time
        if time_interval > 0:
            data_rate_mbps = (total_bytes * 8) / (time_interval * 10**6)
            print(f"Total Packet Length: {total_bytes} bytes")
            print(f"Time Interval: {time_interval} seconds")
            print(f"Data Rate: {data_rate_mbps:.2f} Mbps")
        else:
            print("Invalid time interval, unable to calculate data rate.")
    else:
        print("No relevant packets found.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 Pcap_Lam_1916079.py <pcap_file>")
        sys.exit(1)

    pcap_file_path = sys.argv[1]
    calculate_data_rate(pcap_file_path)
