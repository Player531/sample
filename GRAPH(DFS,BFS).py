# def bfs(graph, source):
#     queue = [ source ]
#     visitedNodes = []

#     while queue:
#         currentNode = queue.pop(0)
#         if currentNode not in visitedNodes:
#             visitedNodes.append(currentNode)
#         for neighbour in graph[currentNode]:
#             if neighbour not in visitedNodes:
#                 queue.append(neighbour)
#     print(visitedNodes)
def bfs(graph, source, destination):
    visited, parent, level = {}, {}, {}
    traversal = []
    queue = [ source ]    
    for node in graph.keys():
        visited[node] = False
        parent[node] = None
        level[node] = -1

    visited[source] = True
    level[source] = 0
    while queue:
        currentNode = queue.pop(0)
        traversal.append(currentNode)
        for neighbor in graph[currentNode]:
            if not visited[neighbor]:
                visited[neighbor] = True
                parent[neighbor] = currentNode
                level[neighbor] = level[currentNode] + 1
                queue.append(neighbor)
    print(traversal)
    print(parent)
    print(level)
    reconstruct_path(source, destination, parent)

def reconstruct_path(s, d, parent):
    path = []
    current = d
    while current is not None:
        path.append(current)
        current = parent[current]
    path.reverse()
    print(path)


def dfs(graph, source):
    visited = {}
    for node in graph:
        visited[node] = False
    
    stack = [ source ]
    visited[source] = True
    dfsTraversal = []
    
    while stack:
        currentNode = stack.pop()
        dfsTraversal.append(currentNode)
        for neighbor in graph[currentNode]:
            if not visited[neighbor]:
                visited[neighbor] = True
                stack.append(neighbor)
    print(dfsTraversal)

def dfs(graph, source, visited, traversal):
    visited[source] = True
    traversal.append(source)
    for neighbor in graph[source]:
        if not visited[neighbor]:
            dfs(graph, neighbor, visited, traversal)

def connectedComponents(graph):
    count = 0
    visited = dict.fromkeys(list(graph.keys()), False)
    for node in graph:
        if not visited[node]:
            dfs(graph, node, visited,[])
            count += 1
    return count


graph = {}
# graphlist = [[1,2],[1,5],[2,5],[2,3],[5,3],[5,4],[3,4]]
# graphlist = [[1,2],[1,7],[2,3],[2,6],[3,4],[3,5],[3,4],[7,8],[7,10],[8,9]]
# graphlist = [[2,1],[2,4],[4,1],[1,5],[1,3]]
# graphlist = [ [0, 1], [1, 2], [0, 3], [3, 4], [4, 7], [3, 7], [6, 7], [4, 5], [4, 6], [5, 6] ]
graphlist = [[1,0],[1,2], [3,4]]

for edge in graphlist:
    a, b = edge
    if a not in graph:
        graph[a] = []
    graph[a].append(b)
    if b not in graph:
        graph[b] = []
    graph[b].append(a)
print(graph)
visited = dict.fromkeys(list(graph), False)
print(visited)
# bfs(graph, 2, 6)
# dfsTraversal = []
# dfs(graph, 2,visited, dfsTraversal)
# print(f"DFS Traversal: {dfsTraversal}")

components = connectedComponents(graph)
print(f"Graph has: {components} components")