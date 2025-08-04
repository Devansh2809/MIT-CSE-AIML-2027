class Graph():
    def __init__(self, num_vertices):
        self.adjList = [[] for _ in range(num_vertices + 1)]  # 1-based indexing

    def addEdge(self, vertex1, vertex2):
        self.adjList[vertex1].append(vertex2)
        self.adjList[vertex2].append(vertex1)  # Since the maze is bidirectional

    def printGraph(self):
        for i in range(1, len(self.adjList)):  # Start from 1 (1-based)
            print(f'{i} -> {self.adjList[i]}')

    def dfs_maze(self, start, exit):
        stack = [(start, [start])]  # Store (current node, path taken)
        visited = set([start])  # Mark the start node as visited

        while stack:
            node, path = stack.pop()

            if node == exit:  # Exit found!
                print("Path to exit:", path)
                return path  # Return the successful path

            for neighbor in self.adjList[node]:  # Natural order
                if neighbor not in visited:
                    visited.add(neighbor)  # Mark as visited **before** pushing
                    stack.append((neighbor, path + [neighbor]))

        print("No exit found!")
        return None  # No path found


# Create the maze as a graph (1-20 nodes)
g = Graph(20)  # Nodes 1 to 20

# Given edges based on the maze image
edges = [
    (1, 2), (2, 3), (3, 8), (4, 5),(1,6),
    (6, 11), (7, 8), (9, 10),
    (11, 12), (13, 14), (14, 9),(12,17),
    (16, 17), (17, 18), (18, 19), (19, 14), (15, 20), (15, 10), (10, 5)
]

# Add edges to graph
for v1, v2 in edges:
    g.addEdge(v1, v2)

g.printGraph()

# Start DFS from node 2 to find exit at node 5
g.dfs_maze(2, 5)
