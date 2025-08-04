class Graph:
    def __init__(self):
        self.graph = {}
        self.vertices = []

    def add_vertex(self, vertex):
        if vertex not in self.vertices:
            self.vertices.append(vertex)
            self.graph[vertex] = []

    def add_edge(self, vertex1, vertex2, weight):
        if vertex1 not in self.vertices:
            self.add_vertex(vertex1)
        if vertex2 not in self.vertices:
            self.add_vertex(vertex2)
            
        self.graph[vertex1].append([vertex2, weight])

    def print_adjacency_list(self):
        print("\nAdjacency List:")
        for vertex in self.graph:
            print(f"{vertex}: {self.graph[vertex]}")

    def print_adjacency_matrix(self):
        vertices_count = len(self.vertices)
        matrix = [[0] * vertices_count for _ in range(vertices_count)]
        
        for i in range(vertices_count):
            for j in range(vertices_count):
                for edge in self.graph[self.vertices[i]]:
                    if edge[0] == self.vertices[j]:
                        matrix[i][j] = edge[1] 

        print("\nAdjacency Matrix:")
        print("  ", end=" ")
        for vertex in self.vertices:
            print(vertex, end=" ")
        print()
        
        for i in range(vertices_count):
            print(f"{self.vertices[i]} ", end=" ")
            for j in range(vertices_count):
                print(matrix[i][j], end=" ")
            print()


if __name__ == "__main__":
    g = Graph()
    
    g.add_edge(1, 2, 1)
    g.add_edge(1, 3, 1)
    g.add_edge(2, 3, 3)
    g.add_edge(3, 4, 4)
    g.add_edge(4, 1, 5)
    
    g.print_adjacency_list()
    g.print_adjacency_matrix()
