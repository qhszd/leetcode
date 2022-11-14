#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Description
# 1662. Check If Two String Arrays are Equivalent

# Given two string arrays word1 and word2,
# return true if the two arrays represent the same string,
# and false otherwise.
# A string is represented by an array if
# the array elements concatenated in order forms the string.


# Example 1:
# Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
# Output: true
# Explanation:
# word1 represents string "ab" + "c" -> "abc"
# word2 represents string "a" + "bc" -> "abc"
# The strings are the same, so return true.

# Example 2:
# Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
# Output: false

# Example 3:
# Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
# Output: true


# Constraints:
# 1 <= word1.length, word2.length <= 103
# 1 <= word1[i].length, word2[i].length <= 103
# 1 <= sum(word1[i].length), sum(word2[i].length) <= 103
# word1[i] and word2[i] consist of lowercase letters.

class Solution:
    def arrayStringsAreEqual(self, word1: list[str], word2: list[str]) -> bool:
        word1 = str(word1)
        word2 = str(word2)
        for i in word1:
            if i =='[' or i ==']' or i ==',' or i == '\'' or i == "\"":
                word1.remove(i)
        for i in word2:
            if i =='[' or i ==']' or i ==',' or i == '\'' or i == "\"":
                word2.remove(i)
        print(word1)
        print(word2)
        return 1

if __name__ == '__main__':
    word1 = ['ab', 'c']
    word2 = ['a', 'bcd']
    obj = Solution()
    
    print(obj.arrayStringsAreEqual(word1, word2))