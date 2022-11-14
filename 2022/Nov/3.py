#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Description
# 1668. Maximum Repeating Substring

# For a string sequence, a string word is k-repeating if word
# concatenated k times is a substring of sequence.
# The word's maximum k-repeating value is the highest value k where word is k-repeating in sequence.
# If word is not a substring of sequence, word's maximum k-repeating value is 0.
# Given strings sequence and word, return the maximum k-repeating value of word in sequence.


# Example 1:
# Input: sequence = "ababc", word = "ab"
# Output: 2
# Explanation: "abab" is a substring in "ababc".

# Example 2:
# Input: sequence = "ababc", word = "ba"
# Output: 1
# Explanation: "ba" is a substring in "ababc". "baba" is not a substring in "ababc".

# Example 3:
# Input: sequence = "ababc", word = "ac"
# Output: 0
# Explanation: "ac" is not a substring in "ababc". 


# Constraints:
# 1 <= sequence.length <= 100
# 1 <= word.length <= 100
# sequence and word contains only lowercase English letters.

class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        # if sequence == word:
        #     return 1
        sequence += '-'
        maxmum = 0
        maxEle = 0
        index = 0
        wordLen = len(word)
        sequLen = len(sequence)
        for i in range(0, sequLen):
            if index == wordLen:
                index = 0
                maxEle += 1
            if sequence[i] != word[index]:
                index = 0
                maxmum = max(maxmum, maxEle)
                maxEle = 0
            index += 1
        maxmum = max(maxmum, maxEle)
        return maxmum
            

if __name__ == '__main__':
    sequence = 'ababc'
    word = 'ac'
    obj = Solution()
    print(obj.maxRepeating(sequence, word))

# Preferable solution
# class Solution:
#     def maxRepeating(self, sequence: str, word: str) -> int:
#         n, m = len(sequence), len(word)
#         if n < m:
#             return 0
#         f = [0] * n
#         for i in range(m - 1, n):
#             valid = True
#             for j in range(m):
#                 if sequence[i - m + j + 1] != word[j]:
#                     valid = False
#                     break
#             if valid:
#                 f[i] = (0 if i == m - 1 else f[i - m]) + 1
#         return max(f)