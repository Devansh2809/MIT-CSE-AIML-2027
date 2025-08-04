import random

def create_world():
    world = [[' ' for _ in range(4)] for _ in range(4)]
    world[random.randint(0, 3)][random.randint(0, 3)] = 'W'  # Wumpus
    world[random.randint(0, 3)][random.randint(0, 3)] = 'P'  # Pit
    world[random.randint(0, 3)][random.randint(0, 3)] = 'G'  # Gold
    return world

def print_world(world, player_pos):
    for i in range(4):
        for j in range(4):
            if (i, j) == player_pos:
                print('A', end=' ')
            else:
                print(world[i][j], end=' ')
        print()

def play_game():
    world = create_world()
    player_pos = (0, 0)
    while True:
        print_world(world, player_pos)
        move = input("Move (w/a/s/d): ").strip().lower()
        if move == 'w' and player_pos[0] > 0:
            player_pos = (player_pos[0] - 1, player_pos[1])
        elif move == 's' and player_pos[0] < 3:
            player_pos = (player_pos[0] + 1, player_pos[1])
        elif move == 'a' and player_pos[1] > 0:
            player_pos = (player_pos[0], player_pos[1] - 1)
        elif move == 'd' and player_pos[1] < 3:
            player_pos = (player_pos[0], player_pos[1] + 1)
        else:
            print("Invalid move!")
            continue
        cell = world[player_pos[0]][player_pos[1]]
        if cell == 'W':
            print("You were eaten by the Wumpus!")
            break
        elif cell == 'P':
            print("You fell into a pit!")
            break
        elif cell == 'G':
            print("You found the gold! You win!")
            break

if __name__ == "__main__":
    play_game()
