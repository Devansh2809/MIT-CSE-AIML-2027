class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adjMatrix = [[0] * num_vertices for _ in range(num_vertices)]  # Initialize matrix with 0s
        self.adjList = [[] for _ in range(num_vertices)]  # Initialize adjacency list

    def addEdge(self, vertex1, weight, vertex2):
        # Convert 1-based input to 0-based index for Python lists
        v1 = vertex1 - 1
        v2 = vertex2 - 1

        # Add edge to adjacency list
        self.adjList[v1].append([vertex2, weight])  # Keep output 1-based

        # Update adjacency matrix
        self.adjMatrix[v1][v2] = weight  # Assign weight

    def printGraph(self):
        print("\nAdjacency List:")
        print("{", end="")
        for i in range(self.num_vertices):
         print(f'"{i+1}": {self.adjList[i]}', end=", " if i < self.num_vertices - 1 else "")
        print("}")

        print("\nAdjacency Matrix:")
        for i in range(self.num_vertices):
            for j in range(self.num_vertices):
                print(self.adjMatrix[i][j], end="  ")
            print()  # Move to the next line after each row

# Example usage
num_vertices = int(input("Enter the number of vertices: "))  # Take number of vertices as input
g = Graph(num_vertices)

num_edges = int(input("Enter the number of edges: "))  # Ask user for the number of edges

for _ in range(num_edges):  # Loop for user-defined number of edges
    values = input("Enter vertex1 weight vertex2: ").split()
    vertex1 = int(values[0])
    weight = int(values[1])
    vertex2 = int(values[2])
    
    g.addEdge(vertex1, weight, vertex2)  # Add the edge to the graph

g.printGraph()  # Print the adjacency list and matrix
