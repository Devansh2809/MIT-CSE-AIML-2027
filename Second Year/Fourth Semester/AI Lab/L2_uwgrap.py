class Graph():
    def __init__(self,num_vertices):
        self.adjList=[[]for _ in range(num_vertices)]
        self.adjMatrix=[[0]*num_vertices for _ in range(num_vertices)]
        self.num_vertices=num_vertices
    def addEdge(self,vertex1,vertex2):
        self.adjList[vertex1].append(vertex2)
        self.adjMatrix[vertex1][vertex2]=1
    def printGraph(self):
        for i in range(self.num_vertices):
            for j in range(self.num_vertices):
                #if self.adjMatrix[i][j]!=0:
                #    print(f'({i}->',end="")
                #    print(f' {j})',end="")
                print(self.adjMatrix[i][j],end=" ")    
            print()
        for i in range(self.num_vertices):
            print(f'{i}->{self.adjList[i]}')
g=Graph(6)
g.addEdge(0,1)
g.addEdge(2,0)
g.addEdge(2,1)
g.addEdge(1,2)
g.addEdge(4,5)
g.addEdge(5,4)
g.printGraph()