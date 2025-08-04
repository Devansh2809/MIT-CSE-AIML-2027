class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adjList = [[] for _ in range(num_vertices)]

    def addEdge(self, vertex1, vertex2):
        self.adjList[vertex1].append(vertex2)  # Directed edge

    def printGraph(self):
        for i in range(self.num_vertices):
            print(f'{i} -> {self.adjList[i]}')
    def cycbfs(self,start):
        queue=[start] 
        visited=set()
        cycle=0
        while queue:
            node=queue.pop(0)
            if node not in visited:
                print(f'{node}',end=" ")
                visited.add(node)
                for neighbor in self.adjList[node]:
                    if neighbor not in visited:
                        queue.append(neighbor)
                    else:
                      cycle+=1
        print(f'{cycle}')

g=Graph(5)
g.addEdge(0,1)
g.addEdge(0,2)
g.addEdge(2,0)
g.addEdge(1,2)
g.addEdge(2,3)
g.addEdge(3,3)
g.addEdge(3,4)
g.addEdge(4,1)
g.addEdge(4,4)
g.cycbfs(2)