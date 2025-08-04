class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adjList = [[] for _ in range(num_vertices)]

    def addEdge(self, v1, v2):
        self.adjList[v1].append(v2)
        self.adjList[v2].append(v1)  # Since it's an undirected graph

    def isBipartiteDFS(self, node, color, colors):
        colors[node] = color  # Color the current node
        for neighbor in self.adjList[node]:
            if colors[neighbor] == -1:  # If not colored, color it with the opposite color
                if not self.isBipartiteDFS(neighbor, 1 - color, colors):
                    return False
            elif colors[neighbor] == colors[node]:  # If neighbor has the same color, it's not bipartite
                return False
        return True

    def checkBipartite(self):
        colors = [-1] * self.num_vertices  # -1 means uncolored
        for i in range(self.num_vertices):  # Check all components
            if colors[i] == -1:  # If not yet visited
                if not self.isBipartiteDFS(i, 0, colors):
                    return False
        return True


# Example usage
g = Graph(6)
g.addEdge(0, 1)
g.addEdge(1, 2)
g.addEdge(2, 3)
g.addEdge(3, 4)
g.addEdge(4, 5)
g.addEdge(5, 0)  # This makes it a cycle

if g.checkBipartite():
    print("The graph is Bipartite")
else:
    print("The graph is NOT Bipartite")
