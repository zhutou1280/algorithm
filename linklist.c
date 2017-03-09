//linklist written in c


LinkList InitList()
{
     LinkList a=(LinkList*)malloc(sizeof(Lnode));
     if(a==NULL)
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


void CreateList(LinkList a,int n)
{
    LinkList q=a;
    int i;
    if(n<1)
    {
       printf("wrong number of elements\n");
       return ;
    }
    for(i=0;i<n;i++)
    {
        LinkList p=(LinkList)malloc(sizeof(Lnode));
        q->next=p;
        printf("please input the %d data\n",i+1);
        scanf("%d",&(p->data));
        q=q->next;
    }
    q->next=NULL;

}

int ListEmpty(LinkList a)
{
    if(a->next==NULL)
      return 0;
    else
      return 1;
}

int ListLength(LinkList a)
{
    int count=0;
    LinkList q=a;
    while(q->next!=NULL)
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
    LinkList p=a;
    LinkList s=(LinkList)malloc(sizeof(Lnode));
    while(p!=NULL&&j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(p==NULL||j>i-1)
     {
        printf("can't insert in that place");
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
    if(p!=NULL&&j<i-1)
     {
         p=p->next;
         j++;
     }
     if(p->next==NULL||j>i-1)
      {
          printf("can't delete'");
        return ;
      }
    q=p->next;
    p->next=q->next;
    free(q);
}



void ListTraverse(LinkList a)
{
    LinkList q,prev=NULL;
    LinkList c=a->next;
    while(c!=NULL)
    {
        q=c->next;
        c->next=prev;
        prev=c;
        c=q;
    }
    c=prev;
    a->next=c;
}


void DestoryList(Lnode* a)
{
    LinkList q=NULL,p=a;

    while(p!=NULL)
    {
        q=p;
        p=q->next;
        free(q);
    }
     if(p==NULL)
        printf("delete successfully");
}

void ClearList(LinkList a)
{
    LinkList p=a->next;
    LinkList q;
    while(p!=NULL)
    {
        printf("ff\n");
       
        q=p;
        p=p->next;
        free(q);
    }
    a->next=NULL;
}