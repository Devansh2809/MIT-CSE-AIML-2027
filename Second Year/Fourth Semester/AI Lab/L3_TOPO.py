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
    def topologicalSortDFS(self):
        visited = set()
        stack = []

        def dfs(node):
            visited.add(node)
            for neighbor in self.adjList[node]:
             if neighbor not in visited:
                dfs(neighbor)
            stack.append(node)  # Push to stack after all neighbors are visited

        for i in range(self.num_vertices):
            if i not in visited:
             dfs(i)

        print("Topological Sort (DFS):", stack[::-1])  # Reverse the stack
    
g=Graph(6)
g.addEdge(5,0)
g.addEdge(3,1)
g.addEdge(2,3)
g.addEdge(5,2)
g.addEdge(4,0)
g.addEdge(4,1)
g.printGraph()
g.topologicalSortDFS()