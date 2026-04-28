#!/bin/bash
# LeetCode Problem 195: Tenth Line
#
# Given a text file file.txt, print only the 10th line of the file.
#
# Example:
# Assume file.txt has the following content:
# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
# Line 11
# ...
#
# Your script should output the 10th line:
# Line 10
#
# Constraints/Assumptions:
#   - The file has at least 10 lines (per sample tests).
#   - If fewer than 10 lines → output nothing (behavior of sed/awk).
#   - One-liner solutions preferred.

# Optimal one-liner solution
sed -n '10p' file.txt

# Explanation of sed command:
#   sed      : Stream editor
#   -n       : Suppress automatic printing of pattern space
#   '10p'    : Print only the 10th line
#   file.txt : Input file
#
# Time Complexity: O(n) - reads the file once
# Space Complexity: O(1)