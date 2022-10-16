#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Description
# 886. Possible Bipartition

# We want to split a group of n people (labeled from 1 to n) into two groups of any size.
# Each person may dislike some other people, and they should not go into the same group.
# Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that
# the person labeled ai does not like the person labeled bi,
# return true if it is possible to split everyone into two groups in this way.


# Example 1:
# Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
# Output: true
# Explanation: group1 [1,4] and group2 [2,3].

# Example 2:
# Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
# Output: false

# Example 3:
# Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
# Output: false


# Constraints:
# 1 <= n <= 2000
# 0 <= dislikes.length <= 104
# dislikes[i].length == 2
# 1 <= dislikes[i][j] <= n
# ai < bi
# All the pairs of dislikes are unique.

# Ideas:
# Implement a matrix which contains nxn 0s, if there is a pair in dislikes,
# put a *1* in the corresponding blank.
# If any diagonal has no 0, then returns False, else then, return True.

# Example:
# Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
#   |  1  2  3  4  5
# -------------------
# 1 |  0  1  0  0  1
# 2 |  1  0  1  0  0
# 3 |  0  1  0  1  0
# 4 |  0  0  1  0  1
# 5 |  1  0  0  1  0
# Output: false


class Solution:
    def possibleBipartition(self, n: int, dislikes: list[list[int]]) -> bool:
        arr = []
        for i in range(n):
            arr.append([])
            for j in range(n):
                arr[i].append(0)
        for i in dislikes:
            arr[i[0] - 1][i[1] - 1] = 1
            arr[i[1] - 1][i[0] - 1] = 1
        for i in arr:
            print(i)
        count = int(n / 2)
        if n % 2 == 1:
            count += 1
        for i in range(count):
            if arr[0][i] == 1:
                print(0, i)
                print(arr[0][i])
                truth = True
                index = i + 1
                j = 1
                num = 1
                while num < n:
                    if index >= n:
                        print('CHECKPOINT! 1#')
                        index -= n - num
                        j = 0
                    if arr[j][index] == 0:
                        print('CHECKPOINT! 2#')
                        truth = False
                        break
                    print(j, index)
                    print(arr[j][index])
                    index += 1
                    num += 1
                    j += 1
                if truth:
                    print('CHECKPOINT! 3#')
                    return False
        return True

if __name__ == '__main__':
    n =10
    dislikes = [[6,9],[1,3],[4,8],[5,6],[2,8],[4,7],[8,9],[2,5],[5,8],[1,2],[6,7],[3,10],[8,10],[1,5],[3,6],[1,10],[7,9],[4,10],[7,10],[1,4],[9,10],[4,6],[2,7],[6,8],[5,7],[3,8],[1,8],[1,7],[7,8],[2,4]]

    sol = Solution()

    if sol.possibleBipartition(n, dislikes):
        print('true')
    else:
        print('false')

# Preferable solution

# class Solution:
#     def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
#         g = [[] for _ in range(n)]
#         for x, y in dislikes:
#             g[x - 1].append(y - 1)
#             g[y - 1].append(x - 1)
#         color = [0] * n  # color[x] = 0 表示未访问节点 x
#         def dfs(x: int, c: int) -> bool:
#             color[x] = c
#             return all(color[y] != c and (color[y] or dfs(y, -c)) for y in g[x])
#         return all(c or dfs(i, 1) for i, c in enumerate(color))