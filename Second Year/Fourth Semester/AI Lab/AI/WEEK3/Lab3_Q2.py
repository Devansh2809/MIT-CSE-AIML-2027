def dfs(graph, node, visited, rec_stack):
    visited[node] = True
    rec_stack[node] = True
    
    for neighbor in graph[node]:
        if not visited[neighbor]:
            if dfs(graph, neighbor, visited, rec_stack):
                return True
        elif rec_stack[neighbor]:

            return True
    
    rec_stack[node] = False
    return False

def count_cycles(graph, n):
    visited = [False] * n
    rec_stack = [False] * n
    cycle_count = 0
    

    for node in range(n):
        if not visited[node]:
            if dfs(graph, node, visited, rec_stack):
                cycle_count += 1
    return cycle_count

graph = {
    0: [1,2],
    1: [2],
    2: [0,3],  
    3: [3],
}

n = len(graph)  
cycles = count_cycles(graph, n)
print(f"Number of cycles detected: {cycles}")
