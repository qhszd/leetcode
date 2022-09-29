/* Discription
788. 旋转数字
我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方（在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？

示例：
输入: 10
输出: 4
解释:
在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。

提示：
N 的取值范围是 [1, 10000].
*/

#define bool int
#define true 1
#define false 0
#include <stdlib.h>
int rotatedDigits(int n){
    int num = 0;
    if ( n < 2 ) {
        return 0;
    }
    for ( int i = 2; i <= n; ++i ) {
        bool truth = false;
        int trans = whatTrans(i);
        if ( trans != i && trans != -1 )
        {
            truth = true;
        }
        if ( truth ) {
            ++num;
        }
    }
    return num;
}

int whatTrans(const int n)
{
    int ori = n;
    int tran = 0;
    for ( int i = 0; ori != 0; ++i )
    {
        int x = ori % 10;
        int y = 0;
        if ( x == 0 ) {
            y = 0;
        } else if ( x == 1 ) {
            y = 1;
        } else if ( x == 2 ) {
            y = 5;
        } else if ( x == 5 ) {
            y = 2;
        } else if ( x == 6 ) {
            y = 9;
        } else if ( x == 8 ) {
            y = 8;
        } else if ( x == 9 ) {
            y = 6;
        } else {
            return -1;
        }
        tran += pow(10, i) * y;
        ori /= 10;
    }
    return tran;
}
