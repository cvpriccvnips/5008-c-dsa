
import random

QUESTIONS = ["Which line(s) of code represents the base case in your recursion, and what values will the variables involved have when the base case is hit? Explain the base case.",
"The recurrence equation for mergesort is T(n) = 2T(n/2) + O(n). Which lines of code contribute the O(n)? Explain how they contribute O(n)",
"Instead of using l, m, and r as indexes and passing in arr[] and temp[], is there a way you could write mergesort in C that would not require extra space? How?",
"Which dataset out of datasets 1-6 in your code will require mergesort to make the most comparisons, and why?",
"The big O runtime of mergesort is O(n log n). Which lines of code contribute the log n?",
"When dataset6 is sorted, what are the values of l and r in the base case, and how many times is the merge function called? Explain how you know.",
]


def main():

    choice = random.choice(QUESTIONS)
    print(choice)

if __name__ == "__main__":
    main()