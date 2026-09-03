# Evan D. Moore
# CSC 1200 - 001
# Dr. Mike Rogers
# 11/09/2020

# This program creates a game of hangman for a user to play.
# The program asks a user to input a word for the game than another user
# can then try and guess.
def draw_hang_loser():
    print(" _________     ")
    print("|         |    ")
    print("|         O    ")
    print("|        /|\   ")
    print("|        / \   ")
    print("|              ")
    print("|              ")


def draw_hang_head_body_legs_la():
    print(" _________     ")
    print("|         |    ")
    print("|         O    ")
    print("|         |\   ")
    print("|        / \   ")
    print("|              ")
    print("|              ")


def draw_hang_head_body_legs():
    print(" _________     ")
    print("|         |    ")
    print("|         O    ")
    print("|         |    ")
    print("|        / \   ")
    print("|              ")
    print("|              ")


def draw_hang_head_body_ll():
    print(" _________     ")
    print("|         |    ")
    print("|         O    ")
    print("|         |    ")
    print("|          \   ")
    print("|              ")
    print("|              ")


def draw_hang_head_body():
    print(" _________     ")
    print("|         |    ")
    print("|         O    ")
    print("|         |    ")
    print("|              ")
    print("|              ")
    print("|              ")


def draw_hang_head():
    print(" _________     ")
    print("|         |    ")
    print("|         O    ")
    print("|              ")
    print("|              ")
    print("|              ")
    print("|              ")


def draw_hang_scaffold():
    print(" _________     ")
    print("|         |    ")
    print("|              ")
    print("|              ")
    print("|              ")
    print("|              ")
    print("|              ")


def draw_hangman(state):
    if state == 0:
        draw_hang_scaffold()
    elif state == 1:
        draw_hang_head()
    elif state == 2:
        draw_hang_head_body()
    elif state == 3:
        draw_hang_head_body_ll()
    elif state == 4:
        draw_hang_head_body_legs()
    elif state == 5:
        draw_hang_head_body_legs_la()
    elif state == 6:
        draw_hang_loser()


def blanks_gone(l):
    if "_" not in l:
        return True
    else:
        return False


def replace_all(orig, working, ch):
    if ch not in orig:
        return False
    for i in range(0, len(orig)):
        if orig[i] == ch:
            working[i] = ch
    return True


def print_list_as_string(l):
    for i in l:
        print(i, end="")
    pass


def string_to_blanks(s):
    e = []
    for i in range(0, len(s)):
        if s[i] == " ":
            e.append(" ")
        else:
            e.append("_")
    return e


def string_to_list(s):
    l = []
    for i in range(0, len(s)):
        l.append(s[i])
    return l


def main():
    state = 0
    losing_state = 6

    print("Please enter the secret phrase: ")
    sentence = input()

    lsentence = string_to_list(sentence)
    lwith_blanks = string_to_blanks(sentence)

    winner = False

    while not winner and state != losing_state:
        draw_hangman(state)
        print()

        # print(lwith_blanks)
        print_list_as_string(lwith_blanks)
        print("Enter a character: ")
        char = input().strip()
        while len(char) != 1:
            print("Invalid input, please enter just one character:")
            char = input().strip()

        success = replace_all(lsentence, lwith_blanks, char)
        if not success:
            state = state + 1
        if blanks_gone(lwith_blanks):
            winner = True

    draw_hangman(state)
    if winner:
        print("CONGRATS! You Win!")
    else:
        print("Sorry, you lose :-(")


main()
