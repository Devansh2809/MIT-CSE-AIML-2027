from queue import PriorityQueue

# Define the graph (adjacency list with weights)
graph = {
    'A': [('B', 6), ('F', 3)],
    'B': [('A', 6), ('D', 2), ('C', 3)],
    'C': [('B', 3), ('D', 5), ('E', 5)],
    'D': [('B', 2), ('C', 5), ('E', 8), ('G', 7)],
    'E': [('C', 5), ('D', 8), ('J', 3)],
    'F': [('A', 3), ('G', 1), ('H', 6)],
    'G': [('D', 7), ('F', 1), ('I', 5)],
    'H': [('F', 6), ('I', 7)],
    'I': [('G', 5), ('H', 7), ('J', 2)],
    'J': [('E', 3), ('I', 2)]
}

# Define heuristic values (estimated cost to reach 'J')
heuristic = {
    'A': 10, 'B': 8, 'C': 5, 'D': 7, 'E': 3,
    'F': 6, 'G': 5, 'H': 7, 'I': 2, 'J': 0
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
            return path
        
        for neighbor, cost in graph[current]:
            temp_g_score = g_score[current] + cost
            if temp_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = temp_g_score
                f_score[neighbor] = temp_g_score + heuristic[neighbor]
                open_list.put((f_score[neighbor], neighbor))

    return None  # No path found

# Find and print the shortest path from A to J
path = a_star_search('A', 'J')
print("Shortest path from A to J:", path)
