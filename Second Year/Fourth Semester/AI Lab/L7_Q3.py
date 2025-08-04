import heapq

# Possible moves: up, down, left, right
MOVES = [(-1, 0), (1, 0), (0, -1), (0, 1)]

# Get valid neighbor states by swapping the empty tile (0)
def get_neighbors(state):
    zero_pos = state.index(0)
    row, col = zero_pos // 3, zero_pos % 3
    neighbors = []

    for dr, dc in MOVES:
        new_row, new_col = row + dr, col + dc
        if 0 <= new_row < 3 and 0 <= new_col < 3:
            new_pos = new_row * 3 + new_col
            new_state = list(state)
            new_state[zero_pos], new_state[new_pos] = new_state[new_pos], new_state[zero_pos]
            neighbors.append(tuple(new_state))

    return neighbors

# Heuristic function: Misplaced Tiles
def misplaced_tiles(state, goal):
    return sum(1 for i in range(9) if state[i] != goal[i] and state[i] != 0)

# A* Algorithm
def a_star(initial, goal):
    pq = []
    heapq.heappush(pq, (misplaced_tiles(initial, goal), 0, initial, None))  # (f_score, g, state, parent)
    
    visited = {initial: None}  # Store parent for path reconstruction
    g_score = {initial: 0}

    while pq:
        _, g, current, parent = heapq.heappop(pq)

        if current == goal:  # Goal reached
            path = []
            while current:
                path.append(current)
                current = visited[current]
            return path[::-1]

        for neighbor in get_neighbors(current):
            new_g = g + 1
            if neighbor not in g_score or new_g < g_score[neighbor]:
                g_score[neighbor] = new_g
                f_score = new_g + misplaced_tiles(neighbor, goal)
                heapq.heappush(pq, (f_score, new_g, neighbor, current))
                visited[neighbor] = current

    return None  # No solution found

# Example Usage
initial_state = (2, 8, 3, 1, 6, 4, 7, 0, 5)
goal_state = (1, 2, 3, 8, 0, 4, 7, 6, 5)

solution_path = a_star(initial_state, goal_state)

if solution_path:
    print("Solution Path:")
    for step in solution_path:
        print(step[:3], "\n", step[3:6], "\n", step[6:], "\n")
else:
    print("No solution found.")
