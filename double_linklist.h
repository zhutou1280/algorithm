/*
//              Author: XIAOPENG HUANG      LANZHOU UNIVERSITY
//              Email: huangxp14@gmail.com
ADT doublelinklist 
{
 *basic method:
 *             DInitList()                       //construct an empty list
 *             DCreateList()                     //create n element in the list
 *             DDestoryList()                    //destory the list
 *             DClearList()                      //make the list to be empty
 *             DListEmpty()                      //figure out weather the list is empty
 *             DListLength()                     //return the length of list
 *             DGetElem()                        //get the element in List
 *             DLocateElem()                     //find the location of  list 
 *             DPriorElem_key                    //give the key and can find the element prior to the key elment
 *             DPriorElem()                      //return the element prior to the input parameter
 *             DNextElem_key()                   //give the key element and find the element hehind it
 *             DNextElem()                       //return the element behind the input parameter
 *             DPriorListInsert()                //insert an element prior to the element that a pointer point to
 *             DNextListInsert()                 //insert an element next to the element that a pointer point to
 *             DListInsert()                     //insert an element
 *             DNextElem_key()                   //insert the element in front of the element which  given pointer point to 
 *             DListDelete()                     //delete an element
 *             DPriorListDelete()                //delete an element prior to the element that the pointer pointer to
 *             DNextListDelete()                 //delete an element  next to the element that point to
 *             DPrintList()                      //print the list 
 }
*/



// ATTENTION : some methods need the parameter that is the head of the list. if you give the wrong parameter to the function \\
//             it may give the wrong answer!  you can see the defination of the function ,if the parament is given 'head'\\
//             that means it only work when you given the list of head. 


#ifndef _DOUBLE_LINKLIST_H
#define _DOUBLE_LINKLIST_H

#define ElemType int
typedef struct double_linklist
{
	ElemType data;
	struct double_linklist* next;
    struct double_linklist* prev;
}Dnode , *Dlinklist;


Dlinklist DInitList();
void DCreateList(Dlinklist head, int n);
int DListEmpty(Dlinklist head);
int DListLength(Dlinklist head);
ElemType  DGetElem(Dlinklist head, int i);
int DLocateElem(Dlinklist head, ElemType key);
ElemType DPriorElem(Dlinklist a);
ElemType DPriorElem_key(Dlinklist head, ElemType key);
ElemType DNextElem(Dlinklist a);
ElemType DNextElem_key(Dlinklist a, ElemType key);
void DListInsert(Dlinklist head, int i, ElemType key);
void DPriorListInsert(Dlinklist a,ElemType key);
void DNextListInsert(Dlinklist a, ElemType key);
void DListDelete(Dlinklist head,int i);
void DPriorListDelete(Dlinklist a);
void DNextListDelete(Dlinklist a);
void DDestroyList(Dlinklist head);
void DClearList(Dlinklist head);
void DPrintList(Dlinklist head);

#endif