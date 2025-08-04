def is_valid(mapping):
    CROSS = (mapping['C'] * 10000 + mapping['R'] * 1000 + mapping['O'] * 100 + 
             mapping['S'] * 10 + mapping['S'])
    ROADS = (mapping['R'] * 10000 + mapping['O'] * 1000 + mapping['A'] * 100 + 
             mapping['D'] * 10 + mapping['S'])
    DANGER = (mapping['D'] * 100000 + mapping['A'] * 10000 + mapping['N'] * 1000 +
              mapping['G'] * 100 + mapping['E'] * 10 + mapping['R'])
    return CROSS + ROADS == DANGER

def solve_cryptarithm():
    letters = 'CROSSROADSANGER'
    unique_letters = sorted(set(letters))
    
    if len(unique_letters) > 10:
        print("Too many unique letters for a valid solution.")
        return
    
    def backtrack(index, used_digits, mapping):
        if index == len(unique_letters):
            if is_valid(mapping):
                print("Solution Found:")
                for k, v in mapping.items():
                    print(f"{k} = {v}")
                return True
            return False
        
        letter = unique_letters[index]
        for digit in range(10):
            if digit not in used_digits:
                mapping[letter] = digit
                used_digits.add(digit)
                
                if backtrack(index + 1, used_digits, mapping):
                    return True
                
                used_digits.remove(digit)
                del mapping[letter]
        return False
    
    if not backtrack(0, set(), {}):
        print("No solution found.")

solve_cryptarithm()