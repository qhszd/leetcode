/* Discription
You would like to reformat the phone number in a certain manner.
Firstly, remove all spaces and dashes.
Then, group the digits from left to right into blocks of length 3 until there are 4 or fewer digits.
The final digits are then grouped as follows:

2 digits: A single block of length 2.
3 digits: A single block of length 3.
4 digits: Two blocks of length 2 each.
The blocks are then joined by dashes.
Notice that the reformatting process should never produce any blocks of length 1 and produce at most two blocks of length 2.

Return the phone number after formatting.

Example 1:
Input: number = "1-23-45 6"
Output: "123-456"
Explanation: The digits are "123456".
Step 1: There are more than 4 digits, so group the next 3 digits. The 1st block is "123".
Step 2: There are 3 digits remaining, so put them in a single block of length 3. The 2nd block is "456".
Joining the blocks gives "123-456".

Example 2:
Input: number = "123 4-567"
Output: "123-45-67"
Explanation: The digits are "1234567".
Step 1: There are more than 4 digits, so group the next 3 digits. The 1st block is "123".
Step 2: There are 4 digits left, so split them into two blocks of length 2. The blocks are "45" and "67".
Joining the blocks gives "123-45-67".

Example 3:
Input: number = "123 4-5678"
Output: "123-456-78"
Explanation: The digits are "12345678".
Step 1: The 1st block is "123".
Step 2: The 2nd block is "456".
Step 3: There are 2 digits left, so put them in a single block of length 2. The 3rd block is "78".
Joining the blocks gives "123-456-78".
 

Constraints:
2 <= number.length <= 100
number consists of digits and the characters '-' and ' '.
There are at least two digits in number.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool        int
#define true        1
#define false       0
#define nullptr     NULL
#define MAXIUM_LEN  135

char* reformatNumber(char*);

// Here's where this program proceeds.
int main(int argc, char* argv[])
{
    char str[23] = "4802066218-13110231308 ";
    puts(reformatNumber(str));
    return 0;
}

char* reformatNumber(char* number)
{
    int lenStr = strlen(number);
    int lenNum = 0;
    for ( int i = 0; i < lenStr; ++i )
    {
        if ( (int)number[i] >= (int)'0' && (int)number[i] <= (int)'9' )
        {
            ++lenNum;
        }
    }

    int index = 0;
    char buffer[MAXIUM_LEN] = { 0 };

    if ( lenNum % 3 == 0 )
    {
        for ( int i = 0; i < lenStr; ++i )
        {
            if ( index % 4 == 3 && ((int)number[i] >= (int)'0' && (int)number[i] <= (int)'9') )
            {
                buffer[index++] = '-';
            }
            if ( (int)number[i] >= (int)'0' && (int)number[i] <= (int)'9' )
            {
                --lenNum;
                buffer[index++] = number[i];
            }
        }
        puts("CHECKPOINT! 1#");
    } else if ( lenNum % 3 == 2 ) {
        for ( int i = 0; i < lenStr; ++i )
        {
            if ( index % 4 == 3 )
            {
                buffer[index++] = '-';
            }
            if ( (int)number[i] >= (int)'0' && (int)number[i] <= (int)'9' )
            {
                --lenNum;
                buffer[index++] = number[i];
            }
        }
        puts("CHECKPOINT! 2#");
    } else {
        int i, j = 0;
        for ( i = 0; i < lenStr; ++i )
        {
            if ( lenNum == 4 )
            {
                break;
            }
            if ( index % 4 == 3 )
            {
                buffer[index++] = '-';
            }
            if ( (int)number[i] >= (int)'0' && (int)number[i] <= (int)'9' )
            {
                --lenNum;
                buffer[index++] = number[i];
            }
            if ( lenNum == 4 )
            {
                buffer[index++] = '-';
                ++i;
                break;
            }
        }
        for ( /* */; i < lenStr; ++i )
        {
            if ( j == 2 )
            {
                buffer[index + j++] = '-';
            }
            if ( (int)number[i] >= (int)'0' && (int)number[i] <= (int)'9' )
            {
                --lenNum;
                buffer[index + j++] = number[i];
            }
        }
        puts("CHECKPOINT! 3#");
    }
    char* result = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
    sprintf(result, "%s", buffer);
    return result;
}