#!/bin/bash
# LeetCode Problem 193: Valid Phone Numbers
#
# Given a text file file.txt that contains a list of phone numbers (one per line),
# write a bash script to print only valid phone numbers.
#
# A valid phone number has exactly one of these two formats:
#   1. (xxx) xxx-xxxx
#   2. xxx-xxx-xxxx
# where x is a digit (0-9).
#
# Assumptions (per problem):
#   - Each line contains only one phone number or invalid string.
#   - No leading/trailing spaces or extra characters in valid numbers.
#
# Example file.txt:
# 987-123-4567
# 123 456 7890
# (123) 456-7890
# 
# Expected output:
# 987-123-4567
# (123) 456-7890

# Solution using grep with extended regex (-E)
grep -E '^(\([0-9]{3}\) [0-9]{3}-[0-9]{4}|[0-9]{3}-[0-9]{3}-[0-9]{4})$' file.txt

# Explanation of the regex:
# ^                                      : Start of line
# (                                      : Begin first alternative (with parentheses)
#   \(                                   : Literal '('
#   [0-9]{3}                             : Exactly 3 digits (area code)
#   \)                                   : Literal ')'
#   [space]                              : Single space
#   [0-9]{3}                             : Exactly 3 digits
#   -                                    : Literal '-'
#   [0-9]{4}                             : Exactly 4 digits
# )                                      : End first alternative
# |                                      : OR
# (                                      : Begin second alternative (no parentheses)
#   [0-9]{3}-[0-9]{3}-[0-9]{4}           : xxx-xxx-xxxx format
# )                                      : End second alternative
# $                                      : End of line
#
# This ensures:
#   - Exact format match (no extra characters).
#   - Only digits where required.
#   - Single space in the (xxx) format.
#
# Time Complexity: O(n * m) where n = number of lines, m = average line length (regex matching)
# Space Complexity: O(1) extra space