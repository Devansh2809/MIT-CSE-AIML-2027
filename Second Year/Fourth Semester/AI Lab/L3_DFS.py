class Graph():
    def __init__(self, num_vertices):
        self.adjList = [[] for _ in range(num_vertices)]  # List of (neighbor, weight) tuples
        self.adjMatrix = [[float('inf')] * num_vertices for _ in range(num_vertices)]  # Infinity for no edge
        self.num_vertices = num_vertices

    def addEdge(self, vertex1, vertex2, weight):
        self.adjList[vertex1].append((vertex2, weight))  # Store tuple (neighbor, weight)
        self.adjMatrix[vertex1][vertex2] = weight  # Store actual weight in the adjacency matrix

    def printGraph(self):
        print("\nAdjacency Matrix:")
        for i in range(self.num_vertices):
            for j in range(self.num_vertices):
                print(self.adjMatrix[i][j] if self.adjMatrix[i][j] != float('inf') else "∞", end=" ")
            print()

        print("\nAdjacency List:")
        for i in range(self.num_vertices):
            print(f'{i} -> {self.adjList[i]}')

    def dfs_weighted(self, start):
        visited = set()
        stack = [(start, 0)]  # Store (node, current cost)

        print("\nDFS Traversal with Weights:")
        while stack:
            node, cost = stack.pop()
            if node not in visited:
                print(f"Node: {node}, Cost: {cost}")  # Print weight information
                visited.add(node)
                for neighbor, weight in reversed(self.adjList[node]):  # Reverse for consistent order
                    if neighbor not in visited:
                        stack.append((neighbor, cost + weight))  # Accumulate cost

# Create a weighted graph (5 nodes)
g = Graph(5)

# Add weighted edges
edges = [
    (0, 1, 2), (0, 2, 4),
    (2, 0, 4), (1, 2, 1),
    (2, 3, 7), (3, 3, 0),
    (3, 4, 3), (4, 1, 5),
    (4, 4, 0)
]

for v1, v2, w in edges:
    g.addEdge(v1, v2, w)

g.printGraph()
g.dfs_weighted(2)
