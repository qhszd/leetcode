#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Description
# 904. Fruit Into Baskets

# You are visiting a farm that has a single row of fruit trees arranged from left to right.
# The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

# You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

# You only have two baskets, and each basket can only hold a single type of fruit.
# There is no limit on the amount of fruit each basket can hold.
# Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right.
# The picked fruits must fit in one of your baskets.
# Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
# Given the integer array fruits, return the maximum number of fruits you can pick.


# Example 1:
# Input: fruits = [1,2,1]
# Output: 3
# Explanation: We can pick from all 3 trees.

# Example 2:
# Input: fruits = [0,1,2,2]
# Output: 3
# Explanation: We can pick from trees [1,2,2].
# If we had started at the first tree, we would only pick from trees [0,1].

# Example 3:
# Input: fruits = [1,2,3,2,2]
# Output: 4
# Explanation: We can pick from trees [2,3,2,2].
# If we had started at the first tree, we would only pick from trees [1,2].


# Constraints:
# 1 <= fruits.length <= 105
# 0 <= fruits[i] < fruits.length

from queue import Queue

class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        q = Queue(2)
        l = len(fruits)
        maxmum = 0
        maxEle = 0
        maxRep = 0
        for i in range(l):
            if q.full() == False and fruits[i] not in q.queue:
                q.put(fruits[i])
                maxEle += 1
                continue
            if fruits[i] in q.queue:
                maxEle += 1
            else:
                if q.get() == fruits[i - 1]:
                    q.get()
                    q.put(fruits[i - 1])
                q.put(fruits[i])
                maxmum = max(maxmum, maxEle)
                maxEle = 2
                index = i - 2
                # print(fruits[index], q.queue)
                while fruits[index] in q.queue and index >= 0:
                    maxEle += 1
                    index -= 1
                # print(fruits[i], maxEle, maxmum)
        maxmum = max(maxmum, maxEle)
        return maxmum

if __name__ == '__main__':
    fruits = [1,1,6,5,6,6,1,1,1,1]
    sol = Solution()
    
    print(sol.totalFruit(fruits))