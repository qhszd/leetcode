/* Discription
面试题 17.19. 消失的两个数字
给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？
以任意顺序返回这两个数字均可。

示例 1:
输入: [1]
输出: [2,3]

示例 2:
输入: [2,3]
输出: [1,4]

提示：
nums.length <= 30000
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#define MAXMUM_SIZE_STACK 2

int* missingTwo(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = 0;
    result[1] = 0;
    for ( int i = 1; i <= numsSize; ++i)
    {
        if (i == nums[i - 1])
        {
            continue;
        }
        while (result[0] == -1 && result[1] == -1)
        {
            result[0] = nums[i - 1];
        }
    }
}

