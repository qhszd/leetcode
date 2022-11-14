#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Decription
# 482. License Key Formatting

# You are given a license key represented as a string s that
# consists of only alphanumeric characters and dashes.
# The string is separated into n + 1 groups by n dashes. You are also given an integer k.
# We want to reformat the string s such that each group contains exactly k characters,
# except for the first group, which could be shorter than k but still must contain at least
# one character. Furthermore, there must be a dash inserted between two groups,
# and you should convert all lowercase letters to uppercase.
# Return the reformatted license key.


# Example 1:
# Input: s = "5F3Z-2e-9-w", k = 4
# Output: "5F3Z-2E9W"
# Explanation: The string s has been split into two parts, each part has 4 characters.
# Note that the two extra dashes are not needed and can be removed.

# Example 2:
# Input: s = "2-5g-3-J", k = 2
# Output: "2-5G-3J"
# Explanation: The string s has been split into three parts,
# each part has 2 characters except the first part as it could be shorter as mentioned above.


# Constraints:
# 1 <= s.length <= 105
# s consists of English letters, digits, and dashes '-'.
# 1 <= k <= 104


class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        l = len(s)
        num = l - len(s.split('-')) + 1
        first = num % k
        index = 0
        rslt = ''
        if num < k:
            for i in s:
                if i == '-':
                    continue
                rslt += i.upper()
            return rslt
        if first != 0:
            j = 0
            while j < first:
                if s[j] == '-':
                    first += 1
                    j += 1
                    continue    
                rslt += s[j].upper()
                j += 1
            rslt += '-'
        for i in range(first, l):
            if s[i] == '-':
                continue
            rslt += s[i].upper()
            index += 1
            if index == k:
                index = 0
                if i != l - 1:
                    truth = False
                    for j in range(i + 1, l):
                        if s[j] != '-':
                            truth = True
                    if truth:
                        rslt += '-'
                    print('CHECKPOINT! 1#')
        return rslt 

if __name__ == '__main__':
    s = "a-a-a-a-"
    k = 1
    obj = Solution()
    print(obj.licenseKeyFormatting(s, k))

# Preferable solution
# class Solution:
#     def licenseKeyFormatting(self, s: str, k: int) -> str:
#         ans = list()
#         cnt = 0
#         for i in range(len(s) - 1, -1, -1):
#             if s[i] != "-":
#                 ans.append(s[i].upper())
#                 cnt += 1
#                 if cnt % k == 0:
#                     ans.append("-")
#         if ans and ans[-1] == "-":
#             ans.pop()
#         return "".join(ans[::-1])