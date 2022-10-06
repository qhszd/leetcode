/* Description
777. Swap Adjacent in LR String
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL",
a move consists of either replacing one occurrence of "XL" with "LX",
or replacing one occurrence of "RX" with "XR".

Given the starting string start and the ending string end,
return True if and only if there exists a sequence of moves to transform one string to the other.


Example 1:
Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: true
Explanation: We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

Example 2:
Input: start = "X", end = "L"
Output: false


Constraints:
1 <= start.length <= 104
start.length == end.length
Both start and end will only consist of characters in 'L', 'R', and 'X'.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/vector.h"

#define bool        int
#define true        1
#define false       0
#define nullptr     NULL

bool canTransform(char*, char*);

// here's where this program proceeds
int main(int argc, char* argv[])
{
    char s1[10] = "RXXLRXRXL\0";
    char s2[10] = "XRLXXRRLX\0";
    if ( canTransform(s1, s2) )
    {
        puts("true");
    } else {
        puts("false");
    }
    return 0;
}

bool canTransform(char* start, char* end){
    int nX1 = 0,
        nX2 = 0,
        len = strlen(start);
    puts("CHECKPOINT! 1#");
    puts(start);
    puts(end);
    if ( len != strlen(end) )
    {
        return false;
    }
    puts("CHECKPOINT! 2#");
    vector* vec = initVector();
    for ( int i = 0; i < len; ++i )
    {
        puts("CHECKPOINT! 3#");
        if ( start[i] == 'X' )
        {
            ++nX1;
        }
        if ( end[i] == 'X' )
        {
            ++nX2;
        }
        // if ( nX2 > nX1 )
        // {
        //     puts("CHECKPOINT! 4#");
        //     return false;
        // }
        if ( end[i] == 'L' || end[i] == 'R' )
        {
            push_back(vec, (int)end[i]);
        }
        if ( start[i] == 'L' || end[i] == 'R' )
        {
            if ( isEmpty(vec) )
            {
                puts("CHECKPOINT! 5#");
                return false;
            } else {
                if ( (int)start[i] != pop_back(vec) )
                {
                    puts("CHECKPOINT! 6#");
                    return false;
                } else {
                    if ( start[i] == 'L' )
                    {
                        if ( nX2 > nX1 )
                        {
                            return false;
                        }
                    } else {
                        if ( nX1 > nX2 )
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}