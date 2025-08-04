import random

def get_heuristic(state):
    """Calculates the number of attacking pairs of queens."""
    attacks = 0
    n = len(state)
    for i in range(n):
        for j in range(i + 1, n):
            if state[i] == state[j] or abs(state[i] - state[j]) == abs(i - j):
                attacks += 1
    return attacks

def get_neighbors(state):
    """Generates all possible next states by moving one queen at a time."""
    n = len(state)
    neighbors = []
    for col in range(n):
        for row in range(n):
            if state[col] != row:  # Avoid generating the same state
                new_state = list(state)
                new_state[col] = row
                neighbors.append(new_state)
    return neighbors

def hill_climbing():
    """Hill Climbing with Random Restart to solve the 8-Queens problem."""
    n = 8  # Size of the board
    state = [random.randint(0, n - 1) for _ in range(n)]  # Random initial state
    while True:
        current_h = get_heuristic(state)
        if current_h == 0:
            return state  # Solution found

        neighbors = get_neighbors(state)
        best_neighbor = min(neighbors, key=get_heuristic)
        best_h = get_heuristic(best_neighbor)

        if best_h >= current_h:
            # No better state found, restart with a new random state
            state = [random.randint(0, n - 1) for _ in range(n)]
        else:
            state = best_neighbor

# Running the algorithm
solution = hill_climbing()
print("Solution:", solution)
