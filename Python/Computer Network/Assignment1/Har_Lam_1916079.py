import json
import sys

def calculate_data_rate(har_file):
    with open(har_file, 'r') as file:
        har_data = json.load(file)

    pages = har_data.get('log', {}).get('pages', [])
    if not pages:
        print("No pages found in the HAR file.")
        return

    onload_time = pages[0].get('pageTimings', {}).get('onLoad', 0)
    if onload_time == 0:
        print("onLoad time is 0 or missing, can't calculate data rate.")
        return

    total_size = sum(entry['response']['content'].get('size', 0) for entry in har_data['log']['entries'])

    onload_time_seconds = onload_time / 1000

    print(f"onLoad Time: {onload_time} ms ({onload_time_seconds} seconds)")
    print(f"Total Content Size: {total_size} bytes")

    data_rate_mbps = (total_size * 8) / (onload_time_seconds * 10**6)
    print(f"Download Data Rate: {data_rate_mbps:.2f} Mbps")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python Har_Lam_1916079.py <har_file>")
        sys.exit(1)

    har_file = sys.argv[1]
    calculate_data_rate(har_file)
