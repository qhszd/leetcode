/* Description
1790. Check if One String Swap Can Make Strings Equal

You are given two strings s1 and s2 of equal length.
A string swap is an operation where you choose two indices in a
string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most
one string swap on exactly one of the strings. Otherwise, return false.


Example 1:
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:
Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Example 3:
Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.


Constraints:
1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.
*/

#define bool        int
#define true        1
#define false       0
#define nullptr     NULL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool areAlmostEqual(char*, char*);

int main(int argc, char* argv[])
{
    char s1[20] = "bank\0";
    char s2[20] = "kanb\0";
    if( areAlmostEqual(s1, s2) ){
        puts("true");
    } else {
        puts("false");
    }
    return 0;
}

bool areAlmostEqual(char* s1, char* s2)
{
    bool res = true;
    if( strcmp(s1, s2) == 0 ){
        /* return true; */
    } else {
        char _s1[3], _s2[3];
        int len = strlen(s1),
            times = 0;
        for( int i = 0; i< len; ++i ){
            if( s1[i] != s2[i] ){
                if( times < 2 ){
                    _s1[times] = s1[i];
                    _s2[1 - times] = s2[i];
                }
                ++times;
            }
            if( times > 2 ){
                // puts("CHECKPOINT! 1#");
                res = false;
            }
        }
        _s1[2] = '\0';
        _s2[2] = '\0';
        // printf("%c%c\n", _s1[0], _s1[1]);
        // printf("%c%c\n", _s2[0], _s2[1]);
        // printf("%d\n", strcmp(_s1, _s2));
        if( res ){
            if( strcmp(_s1, _s2) == 0 ){
                // puts("CHECKPOINT! 2#");
                /* res = true; */
            } else {
                res = false;
            }
        } else {
            /* return false; */
        }
    }
    return res;
}

