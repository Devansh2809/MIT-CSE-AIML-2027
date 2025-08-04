def water_jug_dfs(capacity_a, capacity_b, target):
    visited = set()
    stack = [(0, 0, [])]
    
    while stack:
        jug_a, jug_b, path = stack.pop()
        
        if (jug_a, jug_b) in visited:
            continue
            
        visited.add((jug_a, jug_b))
        current_path = path + [(jug_a, jug_b)]
        
        if jug_a == target or jug_b == target:
            return current_path
            
        if jug_b > 0 and jug_a < capacity_a:
            pour = min(jug_b, capacity_a - jug_a)
            stack.append((jug_a + pour, jug_b - pour, current_path))
        
        if jug_a > 0 and jug_b < capacity_b:
            pour = min(jug_a, capacity_b - jug_b)
            stack.append((jug_a - pour, jug_b + pour, current_path))
        
        if jug_b > 0:
            stack.append((jug_a, 0, current_path))
        
        if jug_a > 0:
            stack.append((0, jug_b, current_path))
        
        if jug_b < capacity_b:
            stack.append((jug_a, capacity_b, current_path))
        
        if jug_a < capacity_a:
            stack.append((capacity_a, jug_b, current_path))
    
    return None

def print_solution(path):
    if path is None:
        print("No solution exists!")
        return
        
    print("\nSolution Path:")
    print("(Jug A, Jug B)")
    for state in path:
        print(state)
    print(f"\nNumber of steps: {len(path) - 1}")

print("Water Jug Problem Solver using DFS")
capacity_a = int(input("Enter capacity of jug A: "))
capacity_b = int(input("Enter capacity of jug B: "))
target = int(input("Enter target amount: "))

solution = water_jug_dfs(capacity_a, capacity_b, target)
print_solution(solution)