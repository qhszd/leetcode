/* Discription
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

Example 1:
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
*/

#include <stdio.h>
#include <stdlib.h>

#define bool    int
#define true    1
#define false   0
#define nullptr NULL

void setZeroes(int**, int, int*);

int main(int argc, char* argv[])
{
    int** matrix = (int**)malloc(sizeof(int*) * 4);
    for ( int i = 0; i < 3; ++i )
    {
        matrix[i] = (int*)malloc(sizeof(int) * 4);
    }
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[0][2] = 2;
    matrix[0][3] = 1;
    matrix[1][0] = 3;
    matrix[1][1] = 0;
    matrix[1][2] = 5;
    matrix[1][3] = 2;
    matrix[2][0] = 1;
    matrix[2][1] = 3;
    matrix[2][2] = 1;
    matrix[2][3] = 5;

    puts("before:");
    for ( int i = 0; i < 3; ++i )
    {
        for ( int j = 0; j < 4; ++j )
        {
            printf("%d ", matrix[i][j]);
        }
        printf("%c", '\n');
    }

    int* colSize = (int*)malloc(sizeof(int) * 1);
    *colSize = 4;
    setZeroes(matrix, 3, colSize);

    puts("after:");
    for ( int i = 0; i < 3; ++i )
    {
        for ( int j = 0; j < 4; ++j )
        {
            printf("%d ", matrix[i][j]);
        }
        printf("%c", '\n');
    }
}

void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    bool row = false;
    bool col = false;
    for ( int i = 0; i < matrixSize; ++i )
    {
        if ( matrix[i][0] == 0 )
        {
            row = true;
            break;
        }
    }
    for ( int i = 0; i < *matrixColSize; ++i )
    {
        if ( matrix[0][i] == 0 )
        {
            col = true;
            break;
        }
    }

    for ( int i = 1; i < matrixSize; ++i )
    {
        for ( int j = 1; j < *matrixColSize; ++j )
        {
            if ( matrix[i][j] == 0 )
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for ( int i = 1; i < matrixSize; ++i )
    {
        if ( matrix[i][0] == 0 )
        {
            for ( int j = 0; j < *matrixColSize; ++j )
            {
                matrix[i][j] = 0;
            }
        }
    }
    for ( int i = 1; i < *matrixColSize; ++i )
    {
        if ( matrix[0][i] == 0 )
        {
            for ( int j = 0; j < matrixSize; ++j )
            {
                matrix[j][i] = 0;
            }
        }
    }
    if ( matrix[0][0] == 0 )
    {
        for ( int i = 1; i < matrixSize; ++i )
        {
            matrix[i][0] = 0;
        }
        for ( int i = 1; i < *matrixColSize; ++i )
        {
            matrix[0][i] = 0;
        }
    }
    if ( row )
    {
        for ( int i = 0; i < matrixSize; ++i )
        {
            matrix[i][0] = 0;
        }
    }
    if ( col )
    {
        for ( int i = 0; i < *matrixColSize; ++i )
        {
            matrix[0][i] = 0;
        }
    }
    return;
}