graph = {
    'Maldon': [('Tiptree', 8)],
    'Tiptree': [('Feering', 3), ('Clacton', 29)],
    'Feering': [('Maldon', 11), ('Blaxhall', 46)],
    'Clacton': [('Maldon', 40), ('Harwich', 17)],
    'Blaxhall': [('Dunwich', 15)],
    'Harwich': [('Tiptee', 31), ('Blaxhall', 40), ('Dunwich', 53)],
    'Dunwich': [('Blaxhall', 17)]
}

def min_cost(queue):
    min_cost = float("inf")
    min_node = None
    for node, cost in queue:
        if cost < min_cost:
            min_cost = cost
            min_node = node
    return min_node, min_cost

def ucs(start, goal):
    queue = [(start, 0)]
    visited = set()
    costs = {start: 0}
    parent = {start: None}

    while queue:
        node, cost = min_cost(queue)
        queue.remove((node, cost))

        if node in visited:
            continue
        visited.add(node)

        if node == goal:
            path = []
            while node:
                path.append(node)
                node = parent[node]
            return cost, list(reversed(path))

        for neighbor, weight in graph.get(node, []):
            new_cost = cost + weight
            if neighbor not in costs or new_cost < costs[neighbor]:
                costs[neighbor] = new_cost
                queue.append((neighbor, new_cost))
                parent[neighbor] = node
    return float("inf"), []

min_cost, shortest_path = ucs('Maldon', 'Dunwich')
print(f"Shortest path from Maldon to Dunwich: {' -> '.join(shortest_path)}")
print(f"Minimum cost: {min_cost}")