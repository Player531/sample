visited = set() # Track visited nodes
topological_order = [] # Store topological order
# Sample DAG
graph = {
  'A': set(['D', 'F']),
  'B': set(['D', 'E']),
  'C': set(['D', 'F']),
  'D': set(['H']),
  'E': set(['F', 'H']),
  'F': set([]),
  'H': set([])
}
def topological_sort_dfs(graph, node):

    # Mark node as visited
    visited.add(node)

    # Recursively call DFS on its neighbors
    for neighbor in graph[node]:
       if neighbor not in visited:
            topological_sort_dfs(graph, neighbor)

     # Add node to topological order
    topological_order.append(node)

for node in graph:
    if node not in visited:
        topological_sort_dfs(graph, node)

print(topological_order)