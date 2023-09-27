from queue import Queue

def bfs(graph, start):
    visited = set()  #dictationary
    queue = Queue()
    queue.put(start)
    visited.add(start)

    while not queue.empty():
        current_node = queue.get()
        print(current_node, end=' ')

        for neighbor in graph[current_node]:
            if neighbor not in visited:
                queue.put(neighbor)
                visited.add(neighbor)

# Example graph represented as an adjacency list
graph = {
    'A': ['B', 'D'],
    'B': ['A','C'],
    'C': ['B'],
    'D': ['A','E','F'],
    'E': ['D','G'],
    'F': ['D','H'],
    'G': ['E'],
    'H': ['F'],
}

# Starting node for BFS traversal
start_node = 'A'

print("BFS Traversal:")
bfs(graph, start_node)


