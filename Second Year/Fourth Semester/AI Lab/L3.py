class Graph():
    def __init__(self,num_vertices):
        self.num_vertices=num_vertices
        self.adjList=[[] for _ in range(num_vertices)]
        self.adjMatrix=[[0]*num_vertices for _ in range(num_vertices)]
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
    def dfs(self,start):
        stack=[start]
        visited=set()
        cycle=0
        print("DFS Traversal")
        while stack:
            node=stack.pop()           
            if node not in visited:
                print(f"{node}",end=" ")
                visited.add(node)
                for neighbor in reversed(self.adjList[node]):
                    if neighbor not in visited:
                        stack.append(neighbor)
                    else:
                        cycle+=1
        
        print(f"\nCycle={cycle}")
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
g.printGraph()
g.dfs(0)

