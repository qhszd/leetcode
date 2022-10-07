# #!/usr/bin/python3
# # -*- coding: UTF-8 -*-

# # Description
# # 1800. Maximum Ascending Subarray Sum

# Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
# A subarray is defined as a contiguous sequence of numbers in an array.
# A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi < numsi+1. Note that a subarray of size 1 is ascending.


# Example 1:
# Input: nums = [10,20,30,5,10,50]
# Output: 65
# Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

# Example 2:
# Input: nums = [10,20,30,40,50]
# Output: 150
# Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.

# Example 3:
# Input: nums = [12,17,15,13,10,11,12]
# Output: 33
# Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.


# Constraints:
# 1 <= nums.length <= 100
# 1 <= nums[i] <= 100

from email.errors import NoBoundaryInMultipartDefect


class Solution:
    def maxAscendingSum(self, nums: list[int]) -> int:
        maxmum = 0
        maxEle = nums[0]
        lenArr = len(nums)
        if lenArr == 1:
            return nums[0]
        for i in range(1, lenArr):
            if nums[i - 1] >= nums[i]:
                maxmum = max(maxmum, maxEle)
                maxEle = nums[i]
            else:
                maxEle += nums[i]
        maxmum = max(maxmum, maxEle)
        return maxmum


if __name__ == '__main__':
    sol = Solution()
    nums = [12,17,15,13,10,11,12]

    print(sol.maxAscendingSum(nums))

# Preferable solution

# class Solution:
#     def maxAscendingSum(self, nums: List[int]) -> int:
#         ans = 0
#         i, n = 0, len(nums)
#         while i < n:
#             s = nums[i]
#             i += 1
#             while i < n and nums[i] > nums[i - 1]:
#                 s += nums[i]
#                 i += 1
#             ans = max(ans, s)
#         return ans