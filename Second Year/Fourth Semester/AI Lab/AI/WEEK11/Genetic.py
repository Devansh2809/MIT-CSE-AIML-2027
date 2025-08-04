import random

# Function to generate a random board configuration
def generate_board(n):
    return [random.randint(0, n-1) for _ in range(n)]

# Fitness function: Counts the number of non-attacking pairs
def fitness(board):
    n = len(board)
    non_attacking_pairs = 0
    
    for i in range(n):
        for j in range(i+1, n):
            if board[i] != board[j] and abs(board[i] - board[j]) != abs(i - j):
                non_attacking_pairs += 1
    
    return non_attacking_pairs

# Selection function using tournament selection
def selection(population):
    tournament = random.sample(population, 5)
    return max(tournament, key=lambda x: x[1])

# Crossover function to generate offspring
def crossover(parent1, parent2):
    n = len(parent1)
    point = random.randint(0, n-1)
    child = parent1[:point] + parent2[point:]
    return child

# Mutation function to introduce variations
def mutate(board, mutation_rate=0.1):
    if random.random() < mutation_rate:
        n = len(board)
        board[random.randint(0, n-1)] = random.randint(0, n-1)
    return board

# Genetic Algorithm for N-Queens
def genetic_algorithm(n, population_size=100, generations=1000):
    population = [(generate_board(n), 0) for _ in range(population_size)]
    population = [(board, fitness(board)) for board, _ in population]
    
    for gen in range(generations):
        population.sort(key=lambda x: x[1], reverse=True)
        
        if population[0][1] == (n * (n - 1)) // 2:
            print(f"Solution found at generation {gen}:", population[0][0])
            return population[0][0]
        
        new_population = []
        for _ in range(population_size // 2):
            parent1 = selection(population)[0]
            parent2 = selection(population)[0]
            child = crossover(parent1, parent2)
            child = mutate(child)
            new_population.append((child, fitness(child)))
        
        population = new_population
    
    print("No solution found.")
    return None

# Run the algorithm for N = 8
genetic_algorithm(8)