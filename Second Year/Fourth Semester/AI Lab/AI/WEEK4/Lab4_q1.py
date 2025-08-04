def topologicalSort(adj, V):
    in_degree = [0] * V

    
    for u in range(V):
        for v in adj[u]:
            in_degree[v] += 1

    
    queue = [i for i in range(V) if in_degree[i] == 0]
    topo_order = []

    while queue:
        
        queue.sort(reverse=True)  
        u = queue.pop(0)  
        topo_order.append(u)

        
        for v in adj[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                queue.append(v)

    
    if len(topo_order) == V:
        print("Topological sorting of the graph:", *topo_order)
    else:
        print("There exists a cycle in the graph. Topological sort is not possible.")

if __name__ == "__main__":
    V = 6
    edges = [[2, 3], [3, 1], [4, 1], [4, 0], [5, 0], [5, 2]]
    
    adj = [[] for _ in range(V)]
    for u, v in edges:
        adj[u].append(v)

    topologicalSort(adj, V)
