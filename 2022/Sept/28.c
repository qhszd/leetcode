/* Discription
Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7. Note that 3, 5, and 7 do not have to be factors, but it should not have any other prime factors. For example, the first several multiples would be (in order) 1, 3, 5, 7, 9, 15, 21.

Example 1:
Input: k = 5
Output: 9
*/

#include "../../lib/vector.h"

int min(int, int);
int getKthMagicNumber(int);

int main(int argc, char* argv[])
{
    printf("%d\n", getKthMagicNumber(2));
}

int getKthMagicNumber(int n){
    vector* res = initVector();
        push_back(res, 1);
        int i = 0, j = 0, k = 0;
        while ( --n ) {
            int t = min(getNum(res, i) * 3, min(getNum(res, j) * 5, getNum(res, k) * 7));
            if (t == getNum(res, i) * 3) ++i;
            if (t == getNum(res, j) * 5) ++j;
            if (t == getNum(res, k) * 7) ++k;

            push_back(res, t);
        }
        return getBack(res);
}

int min(int a, int b)
{
    return a < b ? a : b;
}