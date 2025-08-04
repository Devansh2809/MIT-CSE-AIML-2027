def water_jug_dfs(x, y, target, a, b, visited, memo, path):
    if (a, b) in visited:
        return False  # Already explored this state
    if a == target or b == target or a + b == target:
        path.append((a, b))
        return True  # Found a solution

    visited.add((a, b))  # Mark as visited

    # Check if the result for this state is already computed
    if (a, b) in memo:
        return memo[(a, b)]

    # Possible moves
    moves = [
        (0, b, "Empty Jug 1"),
        (a, 0, "Empty Jug 2"),
        (x, b, "Fill Jug 1"),
        (a, y, "Fill Jug 2"),
        (a - min(a, y - b), b + min(a, y - b), "Pour Jug 1 → Jug 2"),
        (a + min(b, x - a), b - min(b, x - a), "Pour Jug 2 → Jug 1")
    ]

    for new_a, new_b, action in moves:
        if water_jug_dfs(x, y, target, new_a, new_b, visited, memo, path):
            path.append((a, b))  # Track the steps backward
            memo[(a, b)] = True
            return True

    memo[(a, b)] = False
    return False

def can_measure_water(x, y, target):
    if target > x + y:
        return False, []  # Target is larger than total capacity

    path = []
    if water_jug_dfs(x, y, target, 0, 0, set(), {}, path):
        return True, path[::-1]  # Reverse to get the steps in correct order
    return False, []

# Example usage
jug1_capacity = 4
jug2_capacity = 3
target_amount = 2

found, steps = can_measure_water(jug1_capacity, jug2_capacity, target_amount)

if found:
    print(f"Yes, it's possible to measure {target_amount} liters.")
    print("Steps:")
    for step in steps:
        print(f"Jug 1: {step[0]}, Jug 2: {step[1]}")
else:
    print(f"No, it's not possible to measure {target_amount} liters.")
