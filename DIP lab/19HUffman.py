import heapq
from collections import defaultdict, Counter

class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(data):
    frequency_counter = Counter(data)
    priority_queue = [HuffmanNode(char, freq) for char, freq in frequency_counter.items()]
    heapq.heapify(priority_queue)

    while len(priority_queue) > 1:
        left = heapq.heappop(priority_queue)
        right = heapq.heappop(priority_queue)

        merged_node = HuffmanNode(None, left.freq + right.freq)
        merged_node.left = left
        merged_node.right = right

        heapq.heappush(priority_queue, merged_node)

    return priority_queue[0]

def build_huffman_codes(node, current_code, codes):
    if node is not None:
        if node.char is not None:
            codes[node.char] = current_code
        build_huffman_codes(node.left, current_code + "0", codes)
        build_huffman_codes(node.right, current_code + "1", codes)

def huffman_encoding(data):
    if not data:
        return None, {}

    root = build_huffman_tree(data)
    codes = {}
    build_huffman_codes(root, "", codes)

    encoded_data = ''.join(codes[char] for char in data)
    return encoded_data, codes

def huffman_decoding(encoded_data, codes):
    if not encoded_data or not codes:
        return None

    reverse_codes = {code: char for char, code in codes.items()}
    decoded_data = ''
    current_code = ''

    for bit in encoded_data:
        current_code += bit
        if current_code in reverse_codes:
            decoded_data += reverse_codes[current_code]
            current_code = ''

    return decoded_data

# Example usage:
input_data = "hello world"
encoded_data, huffman_codes = huffman_encoding(input_data)

print(f"Original data: {input_data}")
print(f"Encoded data: {encoded_data}")
print(f"Huffman codes: {huffman_codes}")

decoded_data = huffman_decoding(encoded_data, huffman_codes)
print(f"Decoded data: {decoded_data}")
