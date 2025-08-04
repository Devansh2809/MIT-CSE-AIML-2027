graph = {
    'S': [('1', 2), ('3', 5)],
    '1': [('G', 1)],
    '2': [('1', 4)],
    '3': [('1', 5), ('G', 6), ('4', 2)],
    '4': [('2', 4), ('5', 3)],
    '5': [('2', 6), ('G', 3)],
    'G': [('4', 7)]
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

    while queue:
        node, cost = min_cost(queue)
        queue.remove((node, cost))

        if node in visited:
            continue
        visited.add(node)

        if node == goal:
            return cost

        for neighbor, weight in graph.get(node, []):
            new_cost = cost + weight
            if neighbor not in costs or new_cost < costs[neighbor]:
                costs[neighbor] = new_cost
                queue.append((neighbor, new_cost))
    return float("inf")

min_cost = ucs('S', 'G')
print("Minimum cost from S to G is =", min_cost)