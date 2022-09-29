/* Discription
This is a lib file which contains the implement of *vector* in C
    author: shaozhd
    time:   20220927
    loca:   east campus, sysu
*/

#ifndef _VECTOR_IN_C_
#define _VECTOR_IN_C_

#include <stdio.h>
#include <stdlib.h>

#define bool    int
#define true    1
#define false   0
#define nullptr NULL

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int curSize;
} vector;

vector* initVector(void);
void delVector(vector*);
void push_back(vector*, const int);
bool setNum(vector*, const int, const int);
bool isEmpty(const vector*);
bool insertNum(vector*, const int, const int);
int  getNum(const vector*, const int);
int  getBack(const vector*);
int  pop_back(vector*);

#endif