import random

def attacks(board):
    return sum(1 for i in range(len(board)) for j in range(i+1, len(board)) 
               if board[i] == board[j] or abs(board[i] - board[j]) == abs(i - j))

def hill_climb(n=8, max_restarts=100):
    for _ in range(max_restarts):
        board = list(range(n))
        random.shuffle(board)
        
        while True:
            best, best_val = board, attacks(board)
            if best_val == 0: return best
            
            for col in range(n):
                orig_row = board[col]
                for row in range(n):
                    if row != orig_row:
                        board[col] = row
                        if attacks(board) < best_val:
                            best, best_val = list(board), attacks(board)
                board[col] = orig_row
                
            if best == board: break
            board = best
    
    return board

if __name__ == "__main__":
    solution = hill_climb()
    print(f"Solution: {solution}, Attacks: {attacks(solution)}")
    for row in range(8):
        print(''.join('Q' if solution[col] == row else '.' for col in range(8)))