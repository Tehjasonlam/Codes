import requests
from bs4 import BeautifulSoup

def extract_grid_data(url: str) -> dict:
    try:
        response = requests.get(url)
        response.raise_for_status()
    except requests.RequestException as e:
        print(f"Error: {e}")
        return {}

    soup = BeautifulSoup(response.text, 'html.parser')
    grid_data = {}

    # Parse rows in tables directly
    for row in soup.select('table tr'):
        cols = row.find_all('td')
        if len(cols) == 3:
            try:
                x, char, y = int(cols[0].get_text(strip=True)), cols[1].get_text(strip=True), int(cols[2].get_text(strip=True))
                grid_data[(x, y)] = char
            except ValueError:
                continue  # Skip invalid rows

    return grid_data

def create_grid(grid_data: dict) -> str:
    if not grid_data:
        return "No valid grid data found."

    # Determine grid size
    max_x = max((x for x, _ in grid_data), default=0) + 1
    max_y = max((y for _, y in grid_data), default=0) + 1

    # Initialize and populate the grid
    grid = [[' ' for _ in range(max_x)] for _ in range(max_y)]
    for (x, y), char in grid_data.items():
        grid[y][x] = char

    return '\n'.join(''.join(row) for row in reversed(grid))  # Reverse rows for correct orientation

def decode_secret_message(url: str) -> str:
    grid_data = extract_grid_data(url)
    return create_grid(grid_data)

# Example usage
if __name__ == "__main__":
    urls = [
        'https://docs.google.com/document/d/e/2PACX-1vRMx5YQlZNa3ra8dYYxmv-QIQ3YJe8tbI3kqcuC7lQiZm-CSEznKfN_HYNSpoXcZIV3Y_O3YoUB1ecq/pub',
        'https://docs.google.com/document/d/e/2PACX-1vSHesOf9hv2sPOntssYrEdubmMQm8lwjfwv6NPjjmIRYs_FOYXtqrYgjh85jBUebK9swPXh_a5TJ5Kl/pub'
    ]
    for url in urls:
        print(decode_secret_message(url))
