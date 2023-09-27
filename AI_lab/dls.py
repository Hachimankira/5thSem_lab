def dls(graph, start, target, depth_limit, visited=None, parent=None, depth=0):
    if visited is None:
        visited = {}
    if parent is None:
        parent = {}

    visited[start] = True

    if start == target:
        return [start]

    if depth == depth_limit:
        return None

    for neighbor in graph[start]:
        if neighbor not in visited:
            parent[neighbor] = start
            path = dls(graph, neighbor, target, depth_limit, visited, parent, depth + 1)
            if path:
                return [start] + path

    return None

# Example graph represented as an adjacency list
adj_list = {
    "A": ["B", "D"],
    "B": ["A", "C"],
    "C": ["B"],
    "D": ["A", "E", "F"],
    "E": ["D", "F", "G"],
    "F": ["D", "E", "H"],
    "G": ["H", "E"],
    "H": ["F", "G"],
}

start_node = "A"
target_node = "H"
depth_limit = 5

# Perform DLS search with depth limit
path = dls(adj_list, start_node, target_node, depth_limit)

if path:
    print(f"Path from {start_node} to {target_node}: {' -> '.join(path)}")
else:
    print(f"No path found from {start_node} to {target_node} within the depth limit.")
