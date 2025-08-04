class Graph():
    def __init__(self,num_vertices):
        self.adjList=[[]for _ in range(num_vertices)]
        self.adjMatrix=[[0]*num_vertices for _ in range(num_vertices)]
        self.num_vertices=num_vertices
    def addEdge(self,vertex1,vertex2):
        V1=ord(vertex1)-ord('A')
        V2=ord(vertex2)-ord('A')
        self.adjList[V1].append(V2)
        self.adjList[V2].append(V1)
        self.adjMatrix[V1][V2]=1
        self.adjMatrix[V2][V1]=1
    def printGraph(self):
        for i in range(self.num_vertices):
            for j in range(self.num_vertices):
                if self.adjMatrix[i][j]!=0:
                    print(f'({i}->',end="")
                    print(f' {j})',end="")
                #print(self.adjMatrix[i][j],end=" ")    
            print()
        for i in range(self.num_vertices):
           print(f"{chr(i+65)} -> {[chr(v+65) for v in self.adjList[i]]}")
g=Graph(5)
g.addEdge('A','B')
g.addEdge('B','C')
g.addEdge('A','C')
g.addEdge('E','D')
g.addEdge('C','D')
g.printGraph()