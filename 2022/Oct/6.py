#!/usr/bin/python3
# -*- coding: UTF-8 -*-

# Discription
# 927. Three Equal Parts


# You are given an array arr which consists of only zeros and ones,
# divide the array into three non-empty parts such that all of these parts represent the same binary value.

# If it is possible, return any [i, j] with i + 1 < j, such that:

# arr[0], arr[1], ..., arr[i] is the first part,
# arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
# arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
# All three parts have equal binary values.
# If it is not possible, return [-1, -1].

# Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.


# Example 1:
# Input: arr = [1,0,1,0,1]
# Output: [0,3]

# Example 2:
# Input: arr = [1,1,0,1,1]
# Output: [-1,-1]

# Example 3:
# Input: arr = [1,1,0,0,1]
# Output: [0,2]


# Constraints:
# 3 <= arr.length <= 3 * 104
# arr[i] is 0 or 1

class Solution:
    def threeEqualParts(self, arr: list[int]) -> list[int]:
        num = 0
        res = []
        for i in arr:
            if i == 1:
                num += 1
        if num % 3 != 0:
            return [-1, -1]
        if num == 0:
            return [0, len(arr) - 1]
        
        num1 = ''
        num2 = ''
        num3 = ''
        i = 0
        index = 0
        while index < num / 3:
            if arr[0] == 1:
                index += 1
            num1 += str(arr[0])
            arr.remove(arr[0])
            i += 1
        if num1 != '':
            num1 = int(num1)
        else:
            num1 = 0
        res.append(i - 1)

        max_zero_1 = 0
        while arr[0] != 1:
            arr.remove(arr[0])
            i += 1
            max_zero_1 += 1
        
        index = 0
        while index < num / 3:
            if arr[0] == 1:
                index += 1
            num2 += str(arr[0])
            arr.remove(arr[0])
            i += 1
        if num2 != '':
            num2 = int(num2)
        else:
            num2 = 0
        res.append(i)

        max_zero_2 = 0
        while arr[0] != 1:
            arr.remove(arr[0])
            i += 1
            max_zero_2 += 1
        
        index = 0
        while index < num / 3:
            if arr[0] == 1:
                index += 1
            num3 += str(arr[0])
            arr.remove(arr[0])
            i += 1
        if num3 != '':
            num3 = int(num3)
        else:
            num3 = 0

        if len(arr) > max_zero_1 or len(arr) > max_zero_2:
            return [-1, -1]
        elif num1 != num2 or num1 != num3:
            return [-1, -1]
        else:
            res[0] += len(arr)
            res[1] += len(arr)
            return res
        

if __name__ == '__main__':
    # a = [1,0,1,0,1]
    
    sol = Solution()
    print(sol.threeEqualParts(a))

# Preferable solution:

# class Solution:
#     def threeEqualParts(self, arr: List[int]) -> List[int]:
#         s = sum(arr)
#         if s % 3:
#             return [-1, -1]
#         if s == 0:
#             return [0, 2]

#         partial = s // 3
#         first = second = third = cur = 0
#         for i, x in enumerate(arr):
#             if x:
#                 if cur == 0:
#                     first = i
#                 elif cur == partial:
#                     second = i
#                 elif cur == 2 * partial:
#                     third = i
#                 cur += 1
#         n = len(arr)
#         length = n - third
#         if first + length <= second and second + length <= third:
#             i = 0
#             while third + i < n:
#                 if arr[first + i] != arr[second + i] or arr[first + i] != arr[third + i]:
#                     return [-1, -1]
#                 i += 1
#             return [first + length - 1, second + length]
#         return [-1, -1]
