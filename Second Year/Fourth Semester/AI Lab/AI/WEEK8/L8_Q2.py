def is_valid(mapping):
    DONALD = (mapping['D'] * 100000 + mapping['O'] * 10000 + mapping['N'] * 1000 + 
             mapping['A'] * 100 + mapping['L'] * 10 + mapping['D'])
    GERALD = (mapping['G'] * 100000 + mapping['E'] * 10000 + mapping['R'] * 1000 + 
             mapping['A'] * 100 + mapping['L'] * 10 + mapping['D'])
    ROBERT = (mapping['R'] * 100000 + mapping['O'] * 10000 + mapping['B'] * 1000 +
              mapping['E'] * 100 + mapping['R'] * 10 + mapping['T'])
    return DONALD + GERALD == ROBERT

def solve_cryptarithm():
    letters = 'DONALDGERALDROBERT'
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
