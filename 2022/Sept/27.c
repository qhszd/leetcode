/* Discription
面试题 01.02. Check Permutation LCCI
Given two strings,write a method to decide if one is a permutation of the other.

Example 1:

Input: s1 = "abc", s2 = "bca"
Output: true
Example 2:

Input: s1 = "abc", s2 = "bad"
Output: false
Note:

0 <= len(s1) <= 100
0 <= len(s2) <= 100 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool    int
#define true    1
#define false   0

int cmprFunc(const void*, const void*);

bool CheckPermutation(char* s1, char* s2)
{
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    if ( length1 != length2 )
    {
        return false;
    }
    // for ( int i = 0; i < length1; ++i )
    // {

    // }
    qsort(s1, length1, sizeof(char), cmprFunc);

    for ( int i = 0; i < length1; ++i )
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }
    return true;
}

int cmprFunc(const void* a, const void* b)
{
    return ( *(int*)a - *(int*)b );
}

int main(void)
{
    char* s1 = (char*)malloc(sizeof(char) * 5);
    char* s2 = (char*)malloc(sizeof(char) * 5);
    s1 = "abcd\0";
    s2 = "dcba\0";
    if ( CheckPermutation(s1, s2) )
    {
        printf("%s\n", "true");
    } else {
        printf("%s\n", "false");
    }
    return 0;
}