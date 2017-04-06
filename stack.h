/*
*           Author: XIAOPENG HUANG   LANZHOU UNIVERSITY
*           EMAIL:  huangxp14@gmail.com
*   the implementation of stack
*   the following are the ADT stack
*
*   ADT stack
*  {
*   basic method:
*       InitStack();                        Initialize the stack  , malloc memory with the const STACKSIZE
*       DestoryStack();                     destory the stack
*       ClearStack();                        make the stack empty
*       StackEmpty();                       judge the stack whether is empty
*       StackLength();                      get the length of the stack
*       GetTop();                           get the top element of the stack
*       Push();                             push the element into the stack
*       Pop();                              pop the element out of the stacl
*       PrintStack();                       print all the element of the stack
*
    }
*/
#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE  10
#define STACKINCREASE 5
typedef int ElemType ;                     //must to be aware that if you change the type ,you need to change the output of printf() function 

typedef   struct
{
    ElemType* base;               //point to the base of the stack     when it's NULL,it means empty stack
    ElemType* top;                  //point to the top of the stack
    int stacksize;                 //the size of the stack
}Stack;

void InitStack(Stack* s);
void DestroyStack(Stack* s);
void ClearStack(Stack* s);
int StackEmpty(Stack* s);
int StackLength(Stack*  s);
ElemType GetTop(Stack* s);
void  Push(Stack* s,ElemType e);
void Pop(Stack* s);
void PrintStack(Stack* s);
