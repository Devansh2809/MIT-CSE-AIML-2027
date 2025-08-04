print("\nMissionaries and Cannibals Problem\n")
print("\nGame Start: Move all the missionaries and cannibals to the other side of the river.")
print("Rules: The boat can carry at most two people at a time. If at any point, cannibals outnumber missionaries on either side, you lose the game.\n")

IM = 3  # Initial Missionaries count
IC = 3  # Initial Cannibals count
BM = 0  # Boat Missionaries
BC = 0  # Boat Cannibals
RM = 0  # Right side Missionaries
RC = 0  # Right side Cannibals
k = 0

print(f"M M M C C C   |\n")

try:
    while True:
        print("\nLeft side -> Right side new travel")
        aM = int(input("Enter number of Missionaries for left to right travel: "))
        aC = int(input("Enter number of Cannibals for left to right travel: "))

        if (aM + aC) > 2 or (aM + aC) == 0:
            print("Invalid move. Try again!")
            continue
        
        if (IM - aM) < (IC - aC) and (IM - aM) > 0:
            print("You lost! Cannibals outnumbered missionaries.")
            break
        
        IM -= aM
        IC -= aC
        RM += aM
        RC += aC
        k += 1
        
        print("\nCurrent State:")
        for i in range(IM):
            print("M", end=" ")
        for i in range(IC):
            print("C", end=" ")
        print("   |   ", end="")
        for i in range(RM):
            print("M", end=" ")
        for i in range(RC):
            print("C", end=" ")
        print("\n")

        if RM == 3 and RC == 3:
            print("You won the game! Congratulations!")
            print(f"Total attempts: {k}")
            break
        
        print("\nRight side -> Left side new travel")
        bM = int(input("Enter number of Missionaries for right to left travel: "))
        bC = int(input("Enter number of Cannibals for right to left travel: "))
        
        if (bM + bC) > 2 or (bM + bC) == 0:
            print("Invalid move. Try again!")
            continue
        
        if (RM - bM) < (RC - bC) and (RM - bM) > 0:
            print("You lost! Cannibals outnumbered missionaries.")
            break
        
        RM -= bM
        RC -= bC
        IM += bM
        IC += bC
        k += 1
        
        print("\nCurrent State:")
        for i in range(IM):
            print("M", end=" ")
        for i in range(IC):
            print("C", end=" ")
        print("   |   ", end="")
        for i in range(RM):
            print("M", end=" ")
        for i in range(RC):
            print("C", end=" ")
        print("\n")
        
except ValueError:
    print("Invalid input! Please enter numbers only.")
