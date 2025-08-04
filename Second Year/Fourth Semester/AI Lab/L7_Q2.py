from queue import PriorityQueue

# Define the graph (adjacency list with weights)
graph = {
    'S': [('A', 5), ('D', 6), ('B', 9)],
    'A': [('B', 3), ('G10', 9)],
    'B': [('A', 2), ('C', 1)],
    'C': [('S', 6), ('F', 7), ('G20', 5)],
    'D': [('C', 2), ('E', 2), ('S', 1)],
    'E': [('G30', 7)],
    'F': [('D', 2), ('G30', 8)],
    'G10': [],
    'G20': [],
    'G30': []
}

# Goal nodes
goal_nodes = {'G10', 'G20', 'G30'}

# Define heuristic values based on the minimum estimated cost to a goal node
heuristic = {
    'S': 5, 'A': 7, 'B': 3, 'C': 4, 'D': 6, 'E': 5,
    'F': 6, 'G10': 0, 'G20': 0, 'G30': 0
}

# A* Algorithm
def a_star_search(start, goal):
    open_list = PriorityQueue()
    open_list.put((0, start))  # (f-cost, node)
    came_from = {}
    g_score = {node: float('inf') for node in graph}
    g_score[start] = 0
    f_score = {node: float('inf') for node in graph}
    f_score[start] = heuristic[start]

    while not open_list.empty():
        _, current = open_list.get()

        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path, g_score[goal]  # Return the actual cost

        for neighbor, cost in graph[current]:
            temp_g_score = g_score[current] + cost
            if temp_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = temp_g_score
                f_score[neighbor] = temp_g_score + heuristic[neighbor]
                open_list.put((f_score[neighbor], neighbor))

    return None, float('inf')  # No path found

# Find the shortest path to any goal node
best_path = None
min_cost = float('inf')

for goal in goal_nodes:
    path, cost = a_star_search('S', goal)
    if path and cost < min_cost:
        min_cost = cost
        best_path = path

print("Shortest path from S to goal:", best_path)
print("Minimum cost:", min_cost)
