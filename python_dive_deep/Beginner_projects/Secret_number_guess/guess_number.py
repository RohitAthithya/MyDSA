# objective:
# computer has a secret a number
# user needs to guess this number


# solution:
# user gives a number
# computer generates a random number in the range 1 to this given number
# computer asks for a guess
# ask to guess until the user gets it ight
# provide hint: to guess a higher value or lower value - by comparing the user's guess and the generated random number
# ------------------------------s---------------------------------------------------------------------------------------------------------------------

from random import randint

WARNING_INPUT_INT_ONLY: str = "!!! ERROR !!!\nEnter only integers!"

# get a number from the use
max_number = input("Enter the highest number, to decide from: ")
try:
    max_number = int(max_number)
except ValueError:
    print(WARNING_INPUT_INT_ONLY)


# generate the random number
random_number: int = randint(1, max_number)

# until user finds the number correctly prompt the user to guess, provide feedback when and where necessary
guessed_number: int = 0
continue_guessing: bool = True
while continue_guessing:
    try:
        guessed_number: int = int(input(f"Guess a number between 1 and {max_number}: "))
    except ValueError:
        print(WARNING_INPUT_INT_ONLY)
    if guessed_number == random_number:
        continue_guessing = False
        continue
    disp_msg: str = "Guess higher !"
    if guessed_number > random_number:
        disp_msg = "Guess lower !"
    print(disp_msg)

print("you have guess the number correctly!")
