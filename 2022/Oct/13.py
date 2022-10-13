#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Description
# 769. Max Chunks To Make Sorted

# You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
# We split arr into some number of chunks (i.e., partitions), and individually sort each chunk.
# After concatenating them, the result should equal the sorted array.
# Return the largest number of chunks we can make to sort the array.


# Example 1:
# Input: arr = [4,3,2,1,0]
# Output: 1
# Explanation:
# Splitting into two or more chunks will not return the required result.
# For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.

# Example 2:
# Input: arr = [1,0,2,3,4]
# Output: 4
# Explanation:
# We can split into two chunks, such as [1, 0], [2, 3, 4].
# However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.


# Constraints:
# n == arr.length
# 1 <= n <= 10
# 0 <= arr[i] < n
# All the elements of arr are unique.

class Solution:
    def maxChunksToSorted(self, arr: list[int]) -> int:
        l = len(arr)
        maxmum = 0
        res = 0
        for i in range(l):
            maxmum = max(maxmum, arr[i])
            if maxmum == i:
                res += 1
                maxmum = 0
        return res

if __name__ == '__main__':
    arr = [4,3,2,1,0]
    sol = Solution()
    print(sol.maxChunksToSorted(arr))

# Result

# 执行结果：
# 通过 
# 显示详情 添加备注
# 执行用时：
# 20 ms, 在所有 Python3 提交中击败了100%的用户
# 内存消耗：
# 14.9 MB, 在所有 Python3 提交中击败了64.39%的用户
# 通过测试用例：
# 52 / 52