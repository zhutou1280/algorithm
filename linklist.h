/*
//              Author: XIAOPENG HUANG     LANZHOU UNIVERSITY
//              Email: huangxp14@gmail.com

ADT list 
{
 *basic method:
 *             InitList()                       //construct an empty list
 *             DestoryList()                    //destory the list
 *             ClearList()                      //make the list to be empty
 *             ListEmpty()                      //figure out weather the list is empty
 *             ListLength()                     //return the length of list
 *             GetElem()                        //get the element in List
 *             LocateElem()                     //find the location of  list 
 *             PriorElem()                      //return the element prior to the input parameter
 *             NextElem()                       //return the element behind the input parameter
 *             ListInsert()                     //insert an element
 *             ListDelete()                     //delete an element
 *             ListTraverse()                   //traverse the list
}

*/



// ATTENTION : this method need the parameter that is the head of the list. if you give the wrong parameter to the function \\
//             it may give the wrong answer!


#ifndef _LINKLIST_H_
#define  _LINKLIST_H_

#include<stdio.h>


//The implemation are as follows
typedef  int ElemType ;

typedef struct node{
    ElemType data;
    struct node* next;
}Lnode, *LinkList;


LinkList InitList();

void CreateList(LinkList a,int n);

int ListEmpty(LinkList a);

int ListLength(LinkList a);

ElemType GetElem(LinkList a,int i);

int LocateElem(LinkList a,ElemType x);

ElemType PriorElem(LinkList a,ElemType x);

ElemType NextElem(LinkList a,ElemType x);

void ListInsert(LinkList a,int i,ElemType x);

void ListDelete(LinkList a,int i);

void ListTraverse(LinkList a);

void DestoryList(Lnode* a);

void ClearList(LinkList a);

#endif

