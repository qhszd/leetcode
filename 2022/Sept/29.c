/* Discription
面试题 01.09. String Rotation LCCI

Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 (e.g.,"waterbottle" is a rotation of"erbottlewat"). Can you use only one call to the method that checks if one word is a substring of another?

Example 1:
Input: s1 = "waterbottle", s2 = "erbottlewat"
Output: True

Example 2:
Input: s1 = "aa", s2 = "aba"
Output: False

Note:
0 <= s1.length, s2.length <= 100000
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef bool
#define bool int
#endif
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

bool isFlipedString(char*, char*);

int main(int argc, char* argv[])
{
    char* str1 = (char*)malloc(sizeof(char) * 72);
    char* str2 = (char*)malloc(sizeof(char) * 72);
    // str1 = "waterfall";
    // str2 = "erfallwat";
    str1 = "PvcvpkpHwaXQxpgGzURBvHRMvCsCPPmlKBSzXDWSvrxLBPdAvRpgcIwNOVQDdwPIElrAFqmb";
    str2 = "SvrxLBPdAvRpgcIwNOVQDdwPIElrAFqmbPvcvpkpHwaXQxpgGzURBvHRMvCsCPPmlKBSzXDW";
    puts(str1);
    puts(str2);
    if ( isFlipedString(str1, str2) )
    {
        puts("true");
    } else {
        puts("false");
    }
    return 0;
}

bool isFlipedString(char* s1, char* s2)
{
    int len1 = strlen(s1),
        len2 = strlen(s2);
    int j = 0;

    if ( len1 != len2 )
    {
        return false;
    }
    if ( len1 == 0 && len2 == 0 )
    {
        return true;
    }
    bool truth = true;
    while ( j < len2 )
    {
        bool t = true;
        while ( s1[0] != s2[j] && j < len2 )
        {
            ++j;
        }
        // printf("%d %c\n", j, s2[j]);
        if ( j >= len2)
        {
            break;
        }
        int k = j;
        for ( int i = 0; i < len1; ++i )
        {
            if ( k >= len2 )
            {
                k = 0;
            }
            // printf("%c %c\n", s1[i], s2[k]);
            if ( s1[i] != s2[k] )
            {
                t = false;
                ++j;
                break;
            }
            ++k;
        }
        if ( t == true )
        {
            return true;
        }
    }
    return false;
}
