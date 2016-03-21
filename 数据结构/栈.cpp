#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * pNext;
    
}NODE, * PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK,* PSTACK;


void init(PSTACK);
void push(PSTACK,int);
void traverse(PSTACK);
bool pop(PSTACK,int *);
void clear(PSTACK);

int main(void)
{
    int val;    //出栈元素
    
    STACK S;  //定义一个栈
    init(&S);
    push(&S, 123);
    push(&S, 333);
    push(&S, 321);
    traverse(&S);
    pop(&S,&val);
    return 0;
}

void init(PSTACK pS)
{
    pS->pTop=(PNODE)malloc(sizeof(NODE));
    if(NULL==pS->pTop)
    {
        printf("动态内存分配失败");
        exit(-1);
    }
    else
    {
        pS->pBottom=pS->pTop;
        pS->pTop->pNext =NULL;
    }
    return;
}

void push(PSTACK pS,int val)
{
    PNODE pNew=(PNODE)malloc(sizeof(NODE));
    pNew->data=val;
    pNew->pNext=pS->pTop;
    pS->pTop=pNew;
    
    return;
}

void traverse(PSTACK pS)
{
    PNODE P =pS->pTop;
    while (P != pS->pBottom) {
        printf("%d\n",P->data);
        P=P->pNext;
    }
    return;
}

bool pop(PSTACK pS,int * pVal)
{

    if (pS->pTop==pS->pBottom)
    {
        printf("栈为空");
        return false;
    }
    else
    {
        *pVal=pS->pTop->data;
        pS->pTop=pS->pTop->pNext;
        free(pS->pTop);
        pS->pTop=NULL;
        printf("出栈元素%d\n",*pVal);
        return true;
    }

}

void clear(PSTACK pS)
{
    if (pS->pTop==pS->pBottom)
    {
        printf("栈为空");
        return;
    }
    else
    {
        PNODE p=pS->pTop;
        PNODE q=NULL;
        while (p!=pS->pBottom)
        {
            q=p->pNext;
            free(p);
            p=q;
        }
        pS->pTop=pS->pBottom;
        printf("清空成功");
    }
}


