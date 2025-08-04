class Graph:
    def __init__(self):
        self.graph = {}
        self.vertices = []

    def add_vertex(self, vertex):
        if vertex not in self.vertices:
            self.vertices.append(vertex)
            self.graph[vertex] = []

    def add_edge(self, vertex1, vertex2):
        if vertex1 not in self.vertices:
            self.add_vertex(vertex1)
        if vertex2 not in self.vertices:
            self.add_vertex(vertex2)
            
        self.graph[vertex1].append(vertex2)

    def print_adjacency_list(self):
        for vertex in self.graph:
            edges = [f"({vertex} -> {neighbor})" for neighbor in self.graph[vertex]]
            print(" ".join(edges))


if __name__ == "__main__":
    g = Graph()
    
    g.add_edge(0,1)
    g.add_edge(1,2)
    g.add_edge(2,0)
    g.add_edge(2,1)
    g.add_edge(3,2)
    g.add_edge(4,5)
    g.add_edge(5,4)
    
    g.print_adjacency_list()
