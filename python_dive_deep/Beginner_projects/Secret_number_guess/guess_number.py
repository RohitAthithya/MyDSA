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
CHR_HIGHER = "H"
CHR_LOWERER = "L"
CHR_EQUAL = "E"


def user_plays_game():
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
            guessed_number: int = int(
                input(f"Guess a number between 1 and {max_number}: ")
            )
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


def computer_plays_game():

    # computer asks the user about the highest number
    proper_input_given = False
    while not proper_input_given:
        highest_number = input("Enter the highest number: ")
        try:
            highest_number = int(highest_number)
            proper_input_given = True
        except:
            print("Enter a integeral input")
            proper_input_given = False
    # computer takes a guess.
    lower_number = 1
    guess_is_correct = False
    while not guess_is_correct:
        guessed_number = randint(lower_number, highest_number)
        user_response = ""
        while not (
            user_response == CHR_HIGHER
            or user_response == CHR_LOWERER
            or user_response == CHR_EQUAL
        ):
            user_response = input(
                f"I guessed the number to be: {guessed_number}\n"
                f"Guessed number is : Higher[{CHR_HIGHER}] | Lower[{CHR_LOWERER}] | Same[{CHR_EQUAL}]   :"
            )
            user_response = user_response.upper()
        # computer asks if the guessed no. is the no. in user's mind, it asks the user if the guess is higher or lower
        if user_response == CHR_HIGHER:
            # Guessed number is greater than the target number, need to guess lower - decrease the maximum digit
            highest_number = guessed_number + 1
        elif user_response == CHR_LOWERER:
            lower_number = guessed_number - 1
        else:
            guess_is_correct = True
            print("Yay! I got it right!")


# user_plays_game()
computer_plays_game()
