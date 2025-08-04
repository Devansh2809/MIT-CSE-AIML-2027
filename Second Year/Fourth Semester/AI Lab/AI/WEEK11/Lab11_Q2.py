from collections import deque

def is_valid_state(state):
    """Check if a state is valid - no queens attacking each other"""
    for i in range(len(state)):
        for j in range(i + 1, len(state)):
            # Check same row or same diagonal
            if state[i] == state[j] or abs(state[i] - state[j]) == abs(i - j):
                return False
    return True

def get_valid_neighbors(state):
    """Generate valid next states by adding one more queen"""
    if len(state) == 8:  # Complete solution
        return []
    
    neighbors = []
    col = len(state)  # Next column to place queen
    
    # Try placing queen in each row of the next column
    for row in range(8):
        new_state = state + (row,)  # Add new queen
        if is_valid_state(new_state):
            neighbors.append(new_state)
            
    return neighbors

def bfs_queens():
    """Find all solutions to 8-queens using BFS"""
    solutions = []
    queue = deque([()])  # Start with empty board
    
    while queue:
        state = queue.popleft()
        
        if len(state) == 8:  # Complete solution
            solutions.append(state)
            continue
        
        # Get valid next states and add to queue
        for neighbor in get_valid_neighbors(state):
            queue.append(neighbor)
    
    return solutions

def print_solutions(solutions):
    """Print all found solutions"""
    for i, solution in enumerate(solutions):
        print(f"solution: {solution}")

# Run the algorithm
if __name__ == "__main__":
    solutions = bfs_queens()
    print_solutions(solutions)
    print(f"Total solutions found: {len(solutions)}")