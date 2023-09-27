def dfs(graph, start, target, visited=None, parent=None):
    if visited is None:
        visited = {}
    if parent is None:
        parent = {}
    
    visited[start] = True

    if start == target:
        return [start]

    for neighbor in graph[start]:
        if neighbor not in visited:
            parent[neighbor] = start
            path = dfs(graph, neighbor, target, visited, parent)
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

# Perform DFS search
path = dfs(adj_list, start_node, target_node)

if path:
    print("DFS Search Path:")
    print(" -> ".join(path))
else:
    print("Target node not found in the graph.")
