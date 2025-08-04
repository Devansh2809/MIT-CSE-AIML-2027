import numpy as np
import heapq

# Board settings
ROWS = 6
COLS = 7

def create_board():
    return np.zeros((ROWS, COLS), dtype=int)

def print_board(board):
    print(np.flip(board, 0))  # Flip to match game visuals

def is_valid_location(board, col):
    return board[ROWS - 1][col] == 0  # Check if column has space

def get_next_open_row(board, col):
    for r in range(ROWS):
        if board[r][col] == 0:
            return r

def drop_piece(board, row, col, piece):
    board[row][col] = piece

def check_win(board, piece):
    """Check if a player has won (horizontally, vertically, diagonally)."""
    for c in range(COLS - 3):  # Horizontal
        for r in range(ROWS):
            if all(board[r, c + i] == piece for i in range(4)):
                return True
    for c in range(COLS):  # Vertical
        for r in range(ROWS - 3):
            if all(board[r + i, c] == piece for i in range(4)):
                return True
    for c in range(COLS - 3):  # Diagonal (\)
        for r in range(ROWS - 3):
            if all(board[r + i, c + i] == piece for i in range(4)):
                return True
    for c in range(COLS - 3):  # Diagonal (/)
        for r in range(3, ROWS):
            if all(board[r - i, c + i] == piece for i in range(4)):
                return True
    return False

def evaluate_board(board, piece):
    """Heuristic function: Counts number of 2s and 3s in a row."""
    score = 0
    opponent = 2 if piece == 1 else 1  # Opponent's piece

    for c in range(COLS - 3):  # Horizontal
        for r in range(ROWS):
            window = board[r, c:c + 4]
            score += score_window(window, piece, opponent)

    for c in range(COLS):  # Vertical
        for r in range(ROWS - 3):
            window = board[r:r + 4, c]
            score += score_window(window, piece, opponent)

    for c in range(COLS - 3):  # Diagonal (\)
        for r in range(ROWS - 3):
            window = [board[r + i, c + i] for i in range(4)]
            score += score_window(window, piece, opponent)

    for c in range(COLS - 3):  # Diagonal (/)
        for r in range(3, ROWS):
            window = [board[r - i, c + i] for i in range(4)]
            score += score_window(window, piece, opponent)

    return score

def score_window(window, piece, opponent):
    """Evaluates a window of 4 spaces in the board."""
    score = 0
    piece_count = np.count_nonzero(window == piece)
    opponent_count = np.count_nonzero(window == opponent)

    if piece_count == 4:
        score += 100  # Winning move
    elif piece_count == 3 and np.count_nonzero(window == 0) == 1:
        score += 10  # Three in a row
    elif piece_count == 2 and np.count_nonzero(window == 0) == 2:
        score += 5  # Two in a row

    if opponent_count == 3 and np.count_nonzero(window == 0) == 1:
        score -= 8  # Block opponent's winning move

    return score

def get_best_move(board, piece):
    """Best First Search: Uses a priority queue to pick the best move."""
    pq = []  # Min-heap priority queue
    for col in range(COLS):
        if is_valid_location(board, col):
            temp_board = board.copy()
            row = get_next_open_row(temp_board, col)
            drop_piece(temp_board, row, col, piece)
            score = evaluate_board(temp_board, piece)
            heapq.heappush(pq, (-score, col))  # Negative score for max-heap behavior

    if pq:
        return heapq.heappop(pq)[1]  # Return best column

def play_game():
    board = create_board()
    game_over = False
    turn = 0  # 0: Player, 1: AI

    while not game_over:
        print_board(board)

        if turn == 0:  # Human player
            col = int(input("Player 1 (Enter column 0-6): "))
        else:  # AI using BFS (Best First Search)
            col = get_best_move(board, 2)
            print(f"AI chooses column {col}")

        if is_valid_location(board, col):
            row = get_next_open_row(board, col)
            drop_piece(board, row, col, turn + 1)

            if check_win(board, turn + 1):
                print_board(board)
                print(f"Player {turn + 1} wins!")
                game_over = True

        turn = (turn + 1) % 2  # Alternate turns

if __name__ == "__main__":
    play_game()
