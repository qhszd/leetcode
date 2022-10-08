#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Description
# 870. Advantage Shuffle

# You are given two integer arrays nums1 and nums2 both of the same length.
# The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
# Return any permutation of nums1 that maximizes its advantage with respect to nums2.


# Example 1:
# Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
# Output: [2,11,7,15]

# Example 2:
# Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
# Output: [24,32,8,12]


# Constraints:
# 1 <= nums1.length <= 105
# nums2.length == nums1.length
# 0 <= nums1[i], nums2[i] <= 109


class Solution:
    def advantageCount(self, nums1: list[int], nums2: list[int]) -> list[int]:
        length = len(nums1)
        for i in range(length):
            min = 0x7fffffff
            minIndex = i
            for j in range(i, length):
                if nums1[j] > nums2[i]:
                    if nums1[j] < min:
                        min = nums1[j]
                        minIndex = j
            if nums1[minIndex] > nums2[i]:
                temp = nums1[minIndex]
                nums1[minIndex] = nums1[i]
                nums1[i] = temp
            else:
                min = 0x7fffffff
                minIndex = i
                for j in range(i, length):
                    if nums1[j] < min:
                        min = nums1[j]
                        minIndex = j
                temp = nums1[minIndex]
                nums1[minIndex] = nums1[i]
                nums1[i] = temp
        return nums1

                    

if __name__ == '__main__':
    sol = Solution()
    # nums1 = [2, 7, 11, 15]
    # nums2 = [1, 10, 4, 11]
    nums1 = [12,24,8,32]
    nums2 = [13,25,32,11]
    print(sol.advantageCount(nums1, nums2))

# Preferable solution

# class Solution:
#     def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
#         n = len(nums1)
#         idx1, idx2 = list(range(n)), list(range(n))
#         idx1.sort(key=lambda x: nums1[x])
#         idx2.sort(key=lambda x: nums2[x])
#         ans = [0] * n
#         left, right = 0, n - 1
#         for i in range(n):
#             if nums1[idx1[i]] > nums2[idx2[left]]:
#                 ans[idx2[left]] = nums1[idx1[i]]
#                 left += 1
#             else:
#                 ans[idx2[right]] = nums1[idx1[i]]
#                 right -= 1
#         return ans