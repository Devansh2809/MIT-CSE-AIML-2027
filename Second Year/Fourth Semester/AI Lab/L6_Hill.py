import random

def func(x):
    return -1 * (x ** 2) + 4 * x + 10  # Example function (parabolic curve)

def hill_climb(func, x_start, step_size=0.1, max_iterations=1000):
    x = x_start
    for _ in range(max_iterations):
        # Generate neighbors
        x_next = x + random.choice([-step_size, step_size])
        # Keep x within bounds
        x_next = max(-10, min(10, x_next))
        # If the new value is better, move to it
        if func(x_next) > func(x):
            x = x_next
    
    return x, func(x)

# Random starting point within the range
x_start = random.uniform(-10, 10)
print(x_start)
# Find maximum using Hill Climbing
best_x, best_value = hill_climb(func, x_start)
print(f"Maximum value found: f({best_x}) = {best_value}")