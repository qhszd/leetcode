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
0 <= len(s2) <= 100
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool    int
#define true    1
#define false   0

bool CheckPermutation(char* s1, char* s2)
{
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    // printf("%s\n%s\n", s1, s2);
    if ( length1 != length2 )
    {
        return false;
    }

    int* digital1 = (int*)malloc(sizeof(int) * length1);
    int* digital2 = (int*)malloc(sizeof(int) * length2);

    for ( int i = 0; i < length1; ++i )
    {
        digital1[i] = (int)s1[i];
        digital2[i] = (int)s2[i];
    }

    // printf("%s\n", "CHECKPOINT!");
    for ( int i = 0; i < length1; ++i )
    {
        for ( int j = 0; j < length1 - 1; ++j )
        {
            if ( digital1[j] > digital1[j + 1] )
            {
                int temp = digital1[j];
                digital1[j] = digital1[j + 1];
                digital1[j + 1] = temp;
            }
        }
    }
    // printf("%s\n", "CHECKPOINT!");
    for ( int i = 0; i < length2; ++i )
    {
        for ( int j = 0; j < length2 - 1; ++j )
        {
            if ( digital2[j] > digital2[j + 1] )
            {
                int temp = digital2[j];
                digital2[j] = digital2[j + 1];
                digital2[j + 1] = temp;
            }
        }
    }

    // for ( int i = 0; i < length1; ++i )
    // {
    //     printf("%d %d\n", digital1[i], digital2[i]);
    // }
    // printf("%s\n", "CHECKPOINT!");

    for ( int i = 0; i < length1; ++i )
    {
        if (digital1[i] != digital2[i])
        {
            free(digital1);
            free(digital2);
            return false;
        }
    }
    free(digital1);
    free(digital2);
    return true;
}

// int main(int argc, char* argv)
// {
//     char* s1 = (char*)malloc(sizeof(char) * 4);
//     char* s2 = (char*)malloc(sizeof(char) * 4);
//     s1 = "cant";
//     s2 = "tanc";
//     if ( CheckPermutation(s1, s2) )
//     {
//         printf("%s\n", "true");
//     } else {
//         printf("%s\n", "false");
//     }
//     return 0;
// }