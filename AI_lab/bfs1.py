
from queue import Queue
adj_list = {
    "A":["B","D"],
    "B":["A","C"],
    "C":["B"],
    "D":["A","E","F"],
    "E":["D","F","G"],
    "F":["D","E","H"],
    "G":["H","E"],
    "H":["F","G"],
}
visited = { }
level ={ }
parent = { }
bfs_traversal_op=[]
queue= Queue( )

for node in adj_list.keys( ):
  visited[node]= False
  parent[node] = None
  level[node]=-1
# print(Visited)
# print(Parent)
# print(level) 


S="A"
target_node ="D"

visited[S]=True
level[S]=0

queue.put(S)

while not queue.empty():
   u=queue.get()
   bfs_traversal_op.append(u)

   if(u == target_node):
      break

   for V in adj_list[u]:
      if not visited[V]:
         visited[V]=True
         parent[V]=u
         level[V]=level[u]+1
         queue.put(V)

print(bfs_traversal_op)        
    
if target_node in visited:
    path = [target_node]
    while parent[target_node] is not None:
        path.insert(0, parent[target_node])
        target_node = parent[target_node]

    print("BFS Traversal Path:")
    print(" -> ".join(path))
else:
    print("Target node not found in the graph.")