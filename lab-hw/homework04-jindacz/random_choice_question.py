
import random

QUESTIONS = ["which part of the array is already sorted after one pass?",
"how would we sort this array in place without a swap function? What code would change, and how would it change?",
"how many lines would you change in sortIntegers to make this selection rather than insertion sort?",
"which lines of code ensure that this sort is stable, and why?",
"explain your use of a pointer in sortIntegers (you defintely use a pointer. Where is it and why do you use it)",
"What is the minimum code you could change to make this sort descending instead of ascending?",
"How much space does your implmentation of insertion sort use? Could you use less?"]


def main():

    choice = random.choice(QUESTIONS)
    print(choice)

if __name__ == "__main__":
    main()