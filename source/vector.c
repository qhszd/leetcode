#include "../lib/vector.h"

vector* initVector(void)
{
    vector* vec = (vector*)malloc(sizeof(vector));
    Node* new = (Node*)malloc(sizeof(Node));
    new->prev = nullptr;
    new->next = nullptr;
    new->data = -1;
    vec->head = new;
    vec->tail = new;
    vec->curSize = 0;
    return vec;
}
void delVector(vector* vec)
{
    while ( vec->tail != vec->head )
    {
        Node* temp = vec->tail->prev;
        free(vec->tail);
        vec->tail = temp;
    }
    free(vec);
    return;
}
void push_back(vector* vec, const int x)
{
    if ( isEmpty(vec) )
    {
        vec->head->data = x;
    } else {
        Node* new = (Node*)malloc(sizeof(Node));
        new->data = x;
        new->prev = vec->tail;
        new->next = nullptr;
        vec->tail->next = new;
        vec->tail = new;
    }
    ++vec->curSize;
    return;
}
bool setNum(vector* vec, const int index, const int data)
{
    if ( index >= vec->curSize )
    {
        return false;
    }
    int i = 0;
    for (Node* ptr = vec->head; i <= index; ptr = ptr->next)
    {
        if ( i == index )
        {
            ptr->data = data;
            break;
        }
        ++i;
    }
    return true;
}
bool isEmpty(const vector* vec)
{
    if ( vec->curSize )
    {
        return false;
    } else {
        return true;
    }
}
bool insertNum(vector* vec, const int index, const int data)
{
    if ( index >= vec->curSize )
    {
        return false;
    }

    int i = 0;
    Node* ptr = vec->head;

    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;

    while ( i != index )
    {
        ptr = ptr->next;
    }
    ptr->prev->next = new;
    new->prev = ptr->prev;
    new->next = ptr;
    ptr->prev = new;

    return true;
}
int getNum(const vector* vec, const int index)
{
    if ( index >= vec->curSize )
    {
        return -1;
    }
    int i = 0;
    for (Node* ptr = vec->head; i <= index; ptr = ptr->next)
    {
        if ( i == index )
        {
            return ptr->data;
        }
        ++i;
    }
    return -1;
}
int getBack(const vector* vec)
{
    return vec->tail->data;
}
int pop_back(vector* vec)
{
    int data = vec->tail->data;
    Node* prev = vec->tail->prev;
    free(vec->tail);
    vec->tail = prev;
    vec->tail->next = nullptr;
    return data;
}

// // testcases
// #include <time.h>
// int main(int argc, char* argv)
// {
//     vector* vec = initVector();
//     for ( int i = 0; i < 10; ++i )
//     {
//         srand((unsigned)clock());
//         int num = abs(rand());
//         push_back(vec, num);
//     }
//     for ( int i = 0; i < 10; ++i ) {
//         printf("%d\n", getNum(vec, i));
//     }
//     delVector(vec);
//     return 0;
// }