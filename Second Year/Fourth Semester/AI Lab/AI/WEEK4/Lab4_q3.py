def calculate_cost(path, graph):
    cost = 0
    for i in range(len(path) - 1):
        cost += graph[path[i]].get(path[i + 1], float('inf'))
    cost += graph[path[-1]].get(path[0], float('inf'))
    return cost

def generate_permutations(cities, current, result):
    if len(current) == len(cities):
        result.append(current[:])
        return
    
    for city in cities:
        if city not in current:
            current.append(city)
            generate_permutations(cities, current, result)
            current.pop()

def traveling_salesman_bfs(graph):
    cities = list(graph.keys())
    result = []
    generate_permutations(cities, [], result)

    min_cost = float('inf')
    best_path = []

    for path in result:
        cost = calculate_cost(path, graph)
        if cost < min_cost:
            min_cost = cost
            best_path = path

    return best_path + [best_path[0]], min_cost  # Adding the return to the start

graph = {
    'A': {'B': 2, 'C': 3, 'D': 1},
    'B': {'A': 2, 'C': 4, 'D': 2},
    'C': {'A': 3, 'B': 4, 'D': 3},
    'D': {'A': 1, 'B': 2, 'C': 3}
}

best_path, min_cost = traveling_salesman_bfs(graph)
print(f"The best path is: {' → '.join(best_path)}")
print(f"The minimum cost is: {min_cost}")
