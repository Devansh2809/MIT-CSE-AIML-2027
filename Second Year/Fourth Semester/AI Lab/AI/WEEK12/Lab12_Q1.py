import numpy as np

def create_board():
    return np.zeros((6, 7), dtype=int)

def print_board(board):
    print(np.flip(board, 0))

def is_valid_location(board, col):
    return board[5][col] == 0

def get_next_open_row(board, col):
    for r in range(6):
        if board[r][col] == 0:
            return r

def drop_piece(board, row, col, piece):
    board[row][col] = piece

def check_win(board, piece):
    for c in range(4):
        for r in range(6):
            if all(board[r, c+i] == piece for i in range(4)):
                return True
    for c in range(7):
        for r in range(3):
            if all(board[r+i, c] == piece for i in range(4)):
                return True
    for c in range(4):
        for r in range(3):
            if all(board[r+i, c+i] == piece for i in range(4)):
                return True
    for c in range(4):
        for r in range(3, 6):
            if all(board[r-i, c+i] == piece for i in range(4)):
                return True
    return False

def play_game():
    board = create_board()
    game_over = False
    turn = 0
    while not game_over:
        print_board(board)
        col = int(input(f"Player {turn+1} (Enter column 0-6): "))
        if is_valid_location(board, col):
            row = get_next_open_row(board, col)
            drop_piece(board, row, col, turn+1)
            if check_win(board, turn+1):
                print_board(board)
                print(f"Player {turn+1} wins!")
                game_over = True
        turn = (turn + 1) % 2

if __name__ == "__main__":
    play_game()
