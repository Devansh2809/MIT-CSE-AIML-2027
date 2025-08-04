class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adjList = [[] for _ in range(num_vertices)]

    def addEdge(self, vertex1, vertex2):
        self.adjList[vertex1].append(vertex2)  # Directed edge

    def printGraph(self):
        for i in range(self.num_vertices):
            print(f'{i} -> {self.adjList[i]}')

    def topobfs(self):
        in_degree = [0] * self.num_vertices
        
        # Step 1: Calculate in-degree of each vertex
        for i in range(self.num_vertices):
            for neighbor in self.adjList[i]:
                in_degree[neighbor] += 1

        queue = []  # Step 2: Use a list as a queue
        for i in range(self.num_vertices):
            if in_degree[i] == 0:
                queue.append(i)

        topo_order = []
        
        # Step 3: Process the queue
        while queue:
            node = queue.pop(0)  # Simulating queue behavior with list
            topo_order.append(node)

            for neighbor in self.adjList[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)

        # Step 4: Check if topological sorting is possible
        if len(topo_order) == self.num_vertices:
            print("Topological Sort (BFS):", topo_order)
        else:
            print("Cycle detected, topological sorting not possible.")

# Example Usage
g = Graph(6)
g.addEdge(5, 0)
g.addEdge(3, 1)
g.addEdge(2, 3)
g.addEdge(5, 2)
g.addEdge(4, 0)
g.addEdge(4, 1)

g.printGraph()
g.topobfs()
