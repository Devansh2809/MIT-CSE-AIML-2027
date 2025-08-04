def is_valid(mapping):
    MIT = (mapping['M'] * 100 + mapping['I'] * 10 + mapping['T'])
    MANIPAL = (mapping['M'] * 1000000+ mapping['A'] * 100000 + mapping['N'] * 10000 + 
             mapping['I'] * 1000 + mapping['P'] * 100 + mapping['A']*10 + mapping['L'])
    MITMAHE =(mapping['M'] * 1000000+ mapping['I'] * 100000 + mapping['T'] * 10000 + 
             mapping['M'] * 1000 + mapping['A'] * 100 + mapping['H']*10 + mapping['E'])
    return MIT+MANIPAL == MITMAHE

def solve_cryptarithm():
    letters = 'MITMANIPALMITMAHE'
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
