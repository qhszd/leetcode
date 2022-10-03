#!/usr/bin/python3

# Discription
# 1784. Check if Binary String Has at Most One Segment of Ones
# Given a binary string s ​​​​​without leading zeros,
# return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.


# Example 1:
# Input: s = "1001"
# Output: false
# Explanation: The ones do not form a contiguous segment.

# Example 2:
# Input: s = "110"
# Output: true


# Constraints:
# 1 <= s.length <= 100
# s[i]​​​​ is either '0' or '1'.
# s[0] is '1'.

class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        b = s.split('0')
        while '' in b:
            b.remove('')
        if len(b) > 1:
            return False
        else:
            return True

if __name__ == '__main__':
    sol = Solution()
    if sol.checkOnesSegment('1000'):
        print('true')
    else:
        print('false')