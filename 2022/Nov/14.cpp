// Description
// 面试题 05.07. Exchange LCCI

// Write a program to swap odd and even bits in an
// integer with as few instructions as possible
// (e.g., bit 0 and bit 1 are swapped,
// bit 2 and bit 3 are swapped, and so on).

// Example1:
// Input: num = 2（0b10）
// Output 1 (0b01)

// Example2:
// Input: num = 3
// Output: 3

// Note:
// 0 <= num <= 2^30 - 1
// The result integer fits into 32-bit integer.

#include <iostream>
#include <cmath>
#include <string.h>
#include <vector>

class Solution
{
public:
    int exchangeBits(int num)
    {
        std::vector<int> n(32);
        int index = 32;
        while( num != 0 ){
            n[--index] = num % 2;
            num /= 2;
        }
        index = 0;
        while( n[index] == 0 ){
            ++index;
        }
        if( index % 2 == 1 ){
            n[index - 1] = 1;
            n[index] = 0;
            ++index;
        }
        while( index < 32 ){
            int t = n[index];
            n[index] = n[index + 1];
            n[index + 1] = t;
            index += 2;
        }
        // std::string ans = "";
        // for( auto iterator = n.begin(); iterator != n.end(); ++iterator ){
        //     ans += char(*iterator);
        // }
        int ans = 0;
        for( int i = 0; i < 32; ++i ){
            if( n[i] == 1 ){
                ans += pow(2, 31 - i);
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[])
{
    int num = 0b10101;
    std::cout << 0b101010 << std::endl;
    Solution obj = Solution();
    std::cout << obj.exchangeBits(num) << std::endl;
    return 0;
}