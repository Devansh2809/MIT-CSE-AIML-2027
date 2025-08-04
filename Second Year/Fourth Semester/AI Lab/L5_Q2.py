graph = {
    'S': [('A', 5), ('B', 9), ('D', 6)],
    'A': [('B', 3), ('G1', 9)],
    'B': [('A', 2), ('C', 1)],
    'C': [('F', 7), ('G2', 5), ('S', 6)],
    'D': [('C', 2), ('E', 2)],
    'E': [('G3', 7)],
    'F': [('D', 2), ('G3', 8)]
}

def min_cost(queue):
    min_cost = float("inf")
    min_node = None
    for node, cost in queue:
        if cost < min_cost:
            min_cost = cost
            min_node = node
    return min_node, min_cost

def ucs(start, goals):
    queue = [(start, 0)]
    visited = set()
    costs = {start: 0}

    while queue:
        node, cost = min_cost(queue)
        queue.remove((node, cost))

        if node in visited:
            continue
        visited.add(node)

        if node in goals:
            return node, cost

        for neighbor, weight in graph.get(node, []):
            new_cost = cost + weight
            if neighbor not in costs or new_cost < costs[neighbor]:
                costs[neighbor] = new_cost
                queue.append((neighbor, new_cost))
    return None, float("inf")

goal, min_cost = ucs('S', {'G1', 'G2', 'G3'})
print(f"Goal reached: {goal}, with minimum cost: {min_cost}")