import heapq


graph = {
    'S': [('A', 1), ('B', 4), ('C', 2)],
    'A': [('S', 1), ('D', 5)],
    'B': [('S', 4), ('D', 1), ('E', 3)],
    'C': [('S', 2), ('E', 1)],
    'D': [('A', 5), ('B', 1), ('F', 3)],
    'E': [('B', 3), ('C', 1), ('F', 2)],
    'F': [('D', 3), ('E', 2)],
}


heuristic = {
    'S': 6,  
    'A': 5,   
    'B': 4,   
    'C': 3, 
    'D': 2,  
    'E': 0,  
    'F': 0,   
}

def a_star(graph, start, goal_nodes, heuristic):
    open_list = []
    heapq.heappush(open_list, (0 + heuristic[start], start))  # (F, node)
    
    g_costs = {start: 0}  # Stores the cost to reach each node
    parent = {start: None}  # To reconstruct the path

    while open_list:
        _, current = heapq.heappop(open_list)

        
        if current in goal_nodes:
            path = []
            while current is not None:
                path.append(current)
                current = parent[current]
            return path[::-1]  
        
        for neighbor, cost in graph[current]:
            tentative_g_cost = g_costs[current] + cost
            
            if neighbor not in g_costs or tentative_g_cost < g_costs[neighbor]:
                g_costs[neighbor] = tentative_g_cost
                f_cost = tentative_g_cost + heuristic[neighbor]
                heapq.heappush(open_list, (f_cost, neighbor))
                parent[neighbor] = current
    
    return None  


start_node = 'S'
goal_nodes = ['F', 'E']

path = a_star(graph, start_node, goal_nodes, heuristic)

if path:
    print(f"Shortest path from {start_node} to one of the goal nodes {goal_nodes}: {path}")
else:
    print(f"No path found from {start_node} to any of the goal nodes {goal_nodes}")
