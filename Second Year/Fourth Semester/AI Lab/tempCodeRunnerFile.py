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