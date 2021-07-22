import os
import re
import random


def findAllFiles(base):
    for root, ds, fs in os.walk(base):
        for f in fs:
            yield f


def main():
    questions = []
    base = "./"
    ques = re.compile(r".*\d+.*\.(cpp|cc)")
    for file in findAllFiles(base):
        if ques.search(file):
            questions.append(file)
    print(questions[random.randint(0, len(questions))])


if __name__ == "__main__":
    main()
