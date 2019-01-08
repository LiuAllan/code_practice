#!/usr/bin/env python3
import sys
def main():
    num_chars = 0
    num_words = 0
    num_lines = 0
    for line in sys.stdin:
        ccc = line.split()
        print(ccc)
        print(len(ccc))
    #     num_lines = num_lines + 1
    #     num_chars = num_lines + len(line)
    #     line = line.strip()
    #     words = line.split()
    #     num_words = num_words + len(words)
    # print (num_lines, num_words, num_chars)
if __name__ == "__main__":
    main()