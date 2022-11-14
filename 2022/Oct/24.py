#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Description
# 915. Partition Array into Disjoint Intervals

# Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:
# Every element in left is less than or equal to every element in right.
# left and right are non-empty.
# left has the smallest possible size.
# Return the length of left after such a partitioning.
# Test cases are generated such that partitioning exists.


# Example 1:
# Input: nums = [5,0,3,8,6]
# Output: 3
# Explanation: left = [5,0,3], right = [8,6]

# Example 2:
# Input: nums = [1,1,1,0,6,12]
# Output: 4
# Explanation: left = [1,1,1,0], right = [6,12]


# Constraints:
# 2 <= nums.length <= 105
# 0 <= nums[i] <= 106
# There is at least one valid answer for the given input.

class Solution:
    def partitionDisjoint(self, nums: list[int]) -> int:
        if len(nums) == 2:
            return 1
        i = 0
        j = len(nums) - 1
        maxmum = nums[i]
        minimum = nums[j]
        while True:
            if i >= j:
                print(i)
                if max(maxmum, nums[i]) == maxmum:
                    pass
                else:
                    i -= 1
                break
            print(i, j)
            if maxmum <= minimum:
                # i += 1
                j -= 1
                # maxmum = max(maxmum, nums[i])
                minimum = min(minimum, nums[j])
            else:
                i += 1
                maxmum = max(maxmum, nums[i])
        return i + 1
            
        
if __name__ == '__main__':
    obj = Solution()
    nums = [32,57,24,19,0,24,49,67,87,87]
    print(obj.partitionDisjoint(nums))
    
# Preferable solution
# class Solution:
#     def partitionDisjoint(self, nums: List[int]) -> int:
#         n = len(nums)
#         min_right = [0] * n
#         min_right[-1] = nums[-1]
#         for i in range(n - 2, 0, -1):
#             min_right[i] = min(min_right[i + 1], nums[i])

#         max_left = nums[0]
#         for i in range(1, n):
#             if max_left <= min_right[i]:
#                 return i
#             max_left = max(max_left, nums[i])
