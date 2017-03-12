#include<stdio.h>
#include"double_linklist.h"


Dlinklist DInitList()
{
	Dlinklist a= (Dnode*)malloc(sizeof(Dnode));
	a->next = NULL;
	a->prev = NULL;

}


//
void DCreateList(Dlinklist head, int n)
{
	int i;
	Dlinklist p = head;
	if (n < 1)
		printf("wrong size\n");
	for (i = 0; i < n; i++)
	{
		printf("please input the %d number\n", i+1);
		Dlinklist x = (Dnode*)malloc(sizeof(Dnode));
		if (x != NULL)
		{
			scanf("%d", &(x->data));        //be aware the %d,if the Elemtype is not int,it need to be changed
			p->next = x;
			x->prev = p;
            p=p->next;
		}
		else
			exit(0);
	}
	     p->next=NULL;
}


//
int DListEmpty(Dlinklist head)
{
	return head->next == NULL ? 0:1;
}


//
int DListLength(Dlinklist head)
{
	Dlinklist p = head->next;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}


//
ElemType  DGetElem(Dlinklist head, int i)
{
	Dlinklist p = head;
	int length,j;
	if (i < 1)
		printf("wrong index\n");
	length = DListLength(p);
	if (i > length)
		printf("wrong index,not enough element\n");
	for (j = 0; j < i; j++)
	{
		p = p->next;
	 }
	return p->data;
}

//
int DLocateElem(Dlinklist head, ElemType key)
{
	Dlinklist p = head->next;
	int i=1;
	while (p != NULL)
	{
		if (p->data == key)
			return i;
		else
		{
			p = p->next;
			i++;
		}
	}

	printf("the list doesn't have it\n");
	return -1;
}


//find the elememt in front of the element that a point to
ElemType DPriorElem(Dlinklist a)
{
	Dlinklist p = a;
	if (p->prev == NULL)
	{
		printf("no element before it\n");
		return -1;
	}
	else
	{
		return p->prev->data;
	}
}

//
ElemType DPriorElem_key(Dlinklist head, ElemType key)
{
	Dlinklist p = head;
	int i, j;
	j =DLocateElem(p,key);
	if(j==-1)
    {
     return -1;
    }
	for (i = 0; i < j; i++)
		p = p->next;
	return DPriorElem(p);
}


ElemType DNextElem(Dlinklist a)
{
	Dlinklist p = a;
	if (p->next == NULL)
	{
		printf("no element behind it\n");
		return -1;
	}
	else
		return p->next->data;
}


ElemType DNextElem_key(Dlinklist a, ElemType key)
{
	Dlinklist p = a;
	int i, j;
	j = DListLength(p);
	for (i = 0; i < j; i++)
		p = p->next;
	return DNextElem(p);
}

void DListInsert(Dlinklist head, int i, ElemType key)
{
	Dlinklist p = head;
	int j;
	int len = DListLength(head);
	if (i < 1||i>len)
		printf("wrong position\n");
	for (j = 0; j< i; j++)
		p = p->next;

	Dlinklist x = (Dnode*)malloc(sizeof(Dnode));
	if (x != NULL)
	{
		x->data = key;
		x->prev = p->prev;
		p->prev->next = x;
		x->next = p;
	}
	else
	{
		printf("no enough memory\n");
	}
}

void DPriorListInsert(Dlinklist a,ElemType key)
{
	Dlinklist p = a;
	Dlinklist x = (Dlinklist)malloc(sizeof(Dnode));
	if (x != NULL)
	{
		x->data = key;
		x->prev = p->prev;
		p->prev->next = x;
		x->next = p;
	}
	else
		printf("no enough memory\n");
}


void DNextListInsert(Dlinklist a, ElemType key)
{
	Dlinklist p = a;
	Dlinklist x = (Dlinklist)malloc(sizeof(Dnode));
	if (x != NULL)
	{
		x->data = key;
		x->prev = p;
		x->next=p->next;
		p->next = x;
	}
	else
		printf("no enough memory\n");
}


void DListDelete(Dlinklist head,int i)
{
    Dlinklist p=head;
    int length,j;
	if (i < 1)
		printf("wrong index\n");
	length = DListLength(p);
	if (i > length)
		printf("wrong index,not enough element\n");
	for (j = 0; i < i; j++)
	{
		p = p->next;
	 }
    p->next->prev=p->prev;
    p->prev->next=p->next;
    free(p);
}

void DPriorListDelete(Dlinklist a)
{
    if(a->prev==NULL)
    {
       printf("no element in front of it\n");
       return ;
    }
    Dlinklist p=a->prev;
    if(p->prev==NULL)
      {
          p->next->prev=NULL;
          free(p);
      }
    else
    {
      p->next->prev=p->prev;
      p->prev->next=p->next;
      free(p);
    }
}

 void DNextListDelete(Dlinklist a)
 {
     Dlinklist p=a->next;
     if(p==NULL)
     {
         printf("no element behind it\n");
         return ;
     }
     if(p->next==NULL)
     {
         p->prev->next=NULL;
         free(p);
     }
     else
     {
       p->next->prev=p->prev;
       p->prev->next=p->next;
       free(p);
     }
 }

void DDestroyList(Dlinklist head)
{
    Dlinklist p=head,q=NULL;

    while(p!=NULL)
    {
         q=p;
         p=q->next;
         free(q);
    }
    if(p==NULL)
        printf("delete successfully\n");
}

void DClearList(Dlinklist head)
{
    Dlinklist p=head->next;
    Dlinklist q;
    while(p!=NULL)
    {
        printf("ff\n");

        q=p;
        p=p->next;
        free(q);
    }
    head->next=NULL;
}

void DPrintList(Dlinklist head)
{
    Dlinklist p=head;
    while(p!=NULL)
    {
      printf("%d\t",p->data);
      p=p->next;
    }
}