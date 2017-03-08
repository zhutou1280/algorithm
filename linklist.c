//linklist written in c

/*ADT list 
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


//The implemation are as follows

typedef  int ElemType ;
typedef struct node{
    ElemType data;
    struct node* next;
}Lnode, *LinkList;


LinkList  InitList()
{
     LinkList a=(LinkList*)malloc(sizeof(Lnode));
     if(a)
        {
            printf("fail to create a list");
            exit(0);
        }
     else
     {
         a->next=NULL;
         return a;
     }
}


int ListEmpty(LinkList a)
{
    if(a->next)
      return 0;
    else
      return 1; 
}

int ListLength(LinkList a)
{
    int count=0;
    linkList q=a;
    if(q->next)
      {
          count++;
          q=q->next;
      }
      return count;
}

ElemType GetElem(LinkList a,int i)
{   
    int j=1;
    LinkList q=a->next;
    while(q&&j<i)
    {
        q=q->next;
        j++;
    }   
    if(!q||j>i) 
      {
          printf("the number %d element is not exist",i);
          exit(0);
      }
      else
      return q->data;
}


int LocateElem(LinkList a,ElemType x)
{
    int j=1;
    LinkList q=a->next;
    while(q)
      {
          if(q->data==x)
          return j;
          else
          {
              q=q->next;
              j++;
          }
      }
      printf("this element is not in the list\n");
      return -1;
}


ElemType PriorElem(LinkList a,ElemType x)
{
    LinkList q=a->next;
    while(q)
    {
        if(q->next->data==x)
           return q->data;
        else
         {
             q=q->next;
         }
    }
    printf("no element prior to this parameter");
    exit(0);
}

ElemType NextElem(LinkList a,ElemType x)
{
    LinkList q=a->next;
    while(q->next)
    {
        if(q->data==x)
           return q->next->data;
        else
         {
             q=q->next;
         }
    }
    printf("no element Next to this parameter");
    exit(0);
}


void ListInsert(LinkList a,int i,ElemType x)
{
    if(i<=0) 
    {
        printf("the position is not right");
        return ;
    }
    int j=0;
    LinkList q=a->next;
    LinkList s=(LinkList)malloc(sizeof(Lnode));
    while(q&&j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i-1)
     {
        print("can't insert in that place");
        return ;
     }
    s->data=x;
    s->next=p->next;
    p->next=s;
}


void ListDelete(LinkList a,int i)
{
    LinkList p,q;
    int j;
    if (i<1||i>ListLength(a))
    {
        printf("wrong position");
        return ;
    }
    p=a;
    j=0;
    if(p&&j<i-1)
     {
         p=p->next;
         j++;
     }
     if(!(p->next)||j>i-1)
      print("can't delete'");
    q=p->next;
    p->next=q->next;
    free(q);
}



void ListTraverse(LinkList a)
{
    LinkList q,prev=NULL;
    while(a)
    {
        q=a->next;
        a->next=prev;
        prev=a;
        a=q;
    }
    a=prev;
}


void DestoryList(Lnode* a) 
{ 
    LinkList p=a->next;
    while(p)
    {
       LinkList q;        
        q=p;
        p=p->next;
        free(q)  
    }
    free a;
}

void ClearList(LinkList a)
{
    LinkList p=a->next;
    while(p)
    {
       LinkList q;        
        q=p;
        p=p->next;
        free(q)  
    }
    a->next=NULL;
}