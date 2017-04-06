
#include"stack.h"




void InitStack(Stack* s)
{
    s->base=(ElemType*)malloc(STACKSIZE* sizeof(ElemType));
    if(!s->base)
     {
         printf("memory destribution failed\n");
         exit(-1);
     }
     
    s->top=s->base;
    s->stacksize=STACKSIZE;
}

void DestroyStack(Stack* s)
{
    s->top=NULL;
    free(s->base);
    s->stacksize=0;
    free(s);
}

void ClearStack(Stack* s)
{
    s->top=s->base;                    //make stack empty;
}

int StackEmpty(Stack* s)
{
    if(s->base==s->top)                     
      return 1;                         //empty stack
    else
      return 0;                            //!empty stack
}

int StackLength(Stack*  s)
{
   
        return s->top - s->base;
}


ElemType GetTop(Stack* s)
{
    if(!StackEmpty(s))
            return *(s->top);
    else
        {
            printf("the stack is empty\n");
            exit(0);
        }
}

void  Push(Stack* s,ElemType e)
{
    if(s->top- s->base >= s->stacksize-1)
     {
         s->base=(ElemType*)realloc(s->base,s->stacksize+STACKINCREASE);
         if(!s->base)
        {
            printf("memory malloc failed\n");
            exit(-1);
        }
        s->top=s->stacksize+ s->base;
        s->stacksize+=STACKINCREASE;
     }
       s->top++;
       printf("push successfully\t");
       printf("%d\t",e);
        *(s->top)=e;
        printf("s->top=%d\n",*(s->top));
}


void Pop(Stack* s)
{
    if(!StackEmpty(s))
    {
        s->top--;
        printf("Successfully pop it\n");
    }
    else
    {
        printf("the stack is empty,can't pop\n");
        exit(0);
    }
}
/*
void PrintStack(Stack* s)
{
    
    if(!StackEmpty(s))
    {
        ElemType* temp=s->base;
        int i,len;
        len=StackLength(s);
        for( i=1;i<len;i++)
        {
            temp++;
            printf("%d\t",*temp);
        }
    }
    else
     {
         printf("error,no elment in stack\n" );
         exit(0);
     }
}
*/

int  main()
{
    Stack ss;
    Stack* s=&ss;
    int i,len,ele;
    InitStack(s); 
    len=StackLength(s);
      printf("len is%d\n",len);
    Push(s,333);
    len=StackLength(s);
    printf("len is%d\n",len);
  //  PrintStack(s);  

    printf("\ngg\n");
        for(i=1;i<=10;i++)  
         Push(s,i*100);
 //   PrintStack(s);
    len=StackLength(s);
    printf("\nthe stacklength:\t%d\n",len);
    ele=GetTop(s);
    Push(s,100);
    printf("heheh\n");
    Push(s,111);
//    PrintStack(s);
    len=StackLength(s);
    printf("\n length:\t%d\n",len);
    for(i=0;i<10;i++)
     {
        printf("%d\t",*(s->top));
         Pop(s);

     } 
  //  PrintStack(s);
     ClearStack(s);
     len=StackEmpty(s);
     printf("is empty:\t%d",len);
     DestroyStack(s);
     return 0;
}

