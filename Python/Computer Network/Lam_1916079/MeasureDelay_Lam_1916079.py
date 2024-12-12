import requests
import time
import sys
import csv

# Server URL and headers
SERVER_URL = "http://34.239.161.153:5000/delayed-response"
HEADERS = {"Content-Type": "application/json"}

def measure_ping_latency():
    """ Measure basic network latency with a quick request-response check. """
    start_time = time.time()
    try:
        response = requests.get("https://httpbin.org/get")  
        end_time = time.time()
        return end_time - start_time
    except requests.RequestException as e:
        print("Network latency measurement failed:", e)
        return None

def measure_delay(psid, debug=False):
    """ Measure latency and calculate server processing delay. """
    latencies = []
    
    for i in range(5):  
        network_latency = measure_ping_latency()
        if network_latency is None:
            print(f"Network latency measurement failed for sample {i+1}. Skipping this sample.")
            continue
        start_time = time.time()
        try:
            response = requests.post(SERVER_URL, json={"psid": psid}, headers=HEADERS)
            end_time = time.time()
            
            total_latency = end_time - start_time
            processing_delay = total_latency - network_latency

            latencies.append((network_latency, processing_delay))
            
            if debug:
                print(f"Server_access_delay_{i+1},{network_latency:.4f},Processing_delay_{i+1},{processing_delay:.4f}")
        
        except requests.RequestException as e:
            print(f"Request failed for sample {i+1}: {e}")
    
    if latencies:
        avg_network_latency = sum(l[0] for l in latencies) / len(latencies)
        avg_processing_delay = sum(l[1] for l in latencies) / len(latencies)
        return avg_network_latency, avg_processing_delay
    else:
        print("No successful measurements were obtained.")
        return None, None


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: MeasureDelay_Lam_1916079.py [-dbg] <last_two_digits_of_psid>")
        sys.exit(1)
    
    debug_mode = "-dbg" in sys.argv
    psid = sys.argv[-1]
    
    avg_network_latency, avg_processing_delay = measure_delay(psid, debug_mode)
    
    if avg_network_latency is not None and avg_processing_delay is not None:
        if debug_mode:
            print("Final Averages:")
        print(f"{avg_network_latency:.4f},{avg_processing_delay:.4f}")
        
        with open("Final_Results.csv", "w", newline="") as file:
            writer = csv.writer(file)
            writer.writerow(["Server_access_delay", "Processing_delay"])
            writer.writerow([f"{avg_network_latency:.4f}", f"{avg_processing_delay:.4f}"])
