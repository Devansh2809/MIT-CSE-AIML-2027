def bfs_cycle_detection(graph, start, visited):
    queue = [start]
    visited[start] = 1

    while queue:
        node = queue.pop(0)

        for neighbor in graph[node]:
            if visited[neighbor] == 0:
                visited[neighbor] = 1
                queue.append(neighbor)
            elif visited[neighbor] == 1:
                return True

        visited[node] = 2

    return False

def count_cycles(graph, n):
    visited = [0] * n
    cycle_count = 0

    for node in range(n):
        if visited[node] == 0:
            if bfs_cycle_detection(graph, node, visited):
                cycle_count += 1

    return cycle_count

graph = {
    0: [1, 2],
    1: [2],
    2: [0],
    3: [3],
}

n = len(graph)
cycles = count_cycles(graph, n)
print(f"Number of cycles detected: {cycles}")
