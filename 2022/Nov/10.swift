// Description
//551. Student Attendance Record I

//You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
//'A': Absent.
//'L': Late.
//'P': Present.
//The student is eligible for an attendance award if they meet both of the following criteria:
//The student was absent ('A') for strictly fewer than 2 days total.
//The student was never late ('L') for 3 or more consecutive days.
//Return true if the student is eligible for an attendance award, or false otherwise.


//Example 1:
//Input: s = PPALLP
//Output: true
//Explanation: The student has fewer than 2 absences and was never late 3 or more consecutive days.

//Example 2:
//Input: s = PPALLL
//Output: false
//Explanation: The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.


//Constraints:
//1 <= s.length <= 1000
//s[i] is either 'A', 'L', or 'P'.

class Solution
{
    func checkRecord(_ s: String) -> Bool
    {
        var truth = true
        var numA = 0
        var maxL = 0
        for i in s {
            if i == A {
                numA += 1
                maxL = 0
                if numA >= 2 {
                    truth = false
                    break
                }
            } else if i == L {
                maxL += 1
                if maxL >= 3 {
                    truth = false
                    break
                }
            } else {
                maxL = 0
            }
        }
        return truth
    }
}

let obj = Solution()
var s = PPALLP
if obj.checkRecord(s) {
    print(true)
} else {
    print(false)
}

