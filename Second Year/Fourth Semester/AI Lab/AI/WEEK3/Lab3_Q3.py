class Graph:
    def __init__(self):
        self.graph = {}

    def add_vertex(self, vertex):
        if vertex not in self.graph:
            self.graph[vertex] = []

    def add_edge(self, vertex1, vertex2):
        self.add_vertex(vertex1)
        self.add_vertex(vertex2)
        self.graph[vertex1].append(vertex2)
        self.graph[vertex2].append(vertex1)

    def find_path_dfs(self, start, end, path=None):
        if path is None:
            path = []
        path.append(start)
        if start == end:
            return path
        for neighbor in self.graph[start]:
            if neighbor not in path:
                result = self.find_path_dfs(neighbor, end, path.copy())
                if result:
                    return result
        return None

if __name__ == "__main__":
    g = Graph()
    
    g.add_edge(2,1)
    g.add_edge(2,3)
    g.add_edge(3,8)
    g.add_edge(7,8)
    g.add_edge(1,6)
    g.add_edge(6,11)
    g.add_edge(11,12)
    g.add_edge(12,17)
    g.add_edge(16,17)
    g.add_edge(17,18)
    g.add_edge(18,19)
    g.add_edge(19,14)
    g.add_edge(14,13)
    g.add_edge(14,9)
    g.add_edge(9,10)
    g.add_edge(10,15)
    g.add_edge(15,20)
    g.add_edge(10,5)
    g.add_edge(5,4)
    
    path = g.find_path_dfs(2, 20)
    
    if path:
        path_str="->".join([str(num) for num in path])
        print("Path from 2 to 20:", path_str)
    else:
        print("No path found from 2 to 20.")
