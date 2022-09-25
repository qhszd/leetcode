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
