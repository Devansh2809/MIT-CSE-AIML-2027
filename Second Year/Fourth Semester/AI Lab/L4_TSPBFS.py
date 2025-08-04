def tsp_bfs(graph, start):
    # Initialize variables
    queue = [(start, [start], 0)]  # (current_node, path, cost)
    num_nodes = len(graph)
    min_cost = float('inf')
    best_path = None

    while queue:
        # Pop the first element from the queue
        current_node, path, cost = queue.pop(0)

        # If all nodes are visited and we return to the start
        if len(path) == num_nodes and start in graph[current_node]:
            total_cost = cost + graph[current_node][start]
            if total_cost < min_cost:
                min_cost = total_cost
                best_path = path + [start]
            continue

        # Explore neighbors
        for neighbor, weight in graph[current_node].items():
            if neighbor not in path:  # Avoid revisiting nodes
                queue.append((neighbor, path + [neighbor], cost + weight))

    return best_path, min_cost


# Graph representation
graph = {
    'A': {'B': 2, 'C': 3, 'D': 1},
    'B': {'A': 2, 'C': 4, 'D': 2},
    'C': {'A': 3, 'B': 4, 'D': 3},
    'D': {'A': 1, 'B': 2, 'C': 3}
}

# Solve TSP using BFS
start_node = 'A'
path, cost = tsp_bfs(graph, start_node)

print(f"Best Path: {path}")
print(f"Minimum Cost: {cost}")
