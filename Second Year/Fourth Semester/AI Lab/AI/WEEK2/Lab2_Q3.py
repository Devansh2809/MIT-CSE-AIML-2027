class Graph:
    def __init__(self, count, vertices):
        self.count = count
        self.vertices = vertices
        self.adj_list = {v: [] for v in self.vertices}
        self.adj_matrix = [[0] * count for i in range(count)]
    def add_egde(self, u, v):
        dic = dict(zip(self.vertices, range(self.count)))
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)
        self.adj_matrix[dic[u]][dic[v]] = 1
        self.adj_matrix[dic[v]][dic[u]] = 1
    def display(self):
        print("Adjacency List:\n[", end='')
        for node, edges in self.adj_list.items():
            print(f"{node}:{edges}")
            print("]")
        print("\nAdjacency Matrix:")
        for row in self.adj_matrix:
            print(row, end="\n")
count = 5
vertices = ['A', 'B', 'C', 'D', 'E']
edges = [('A', 'B'), ('A', 'C'), ('A', 'E'), ('B', 'C'), ('B','D'),('C', 'E'), ('C', 'D')]
graph = Graph(count, vertices)
for u, v in edges:
    graph.add_egde(u, v)
graph.display() 