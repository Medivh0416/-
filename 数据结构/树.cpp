//
//  树.cpp
//  数据结构
//
//  Created by Xuchu on 15/12/23.
//  Copyright © 2015年 Xuchu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct BTNode
{
    int data;
    struct BTNode * pLchild;
    struct BTNode * pRchild;
};

struct BTNode * createBTree(void);
void PreTracerseBTree(BTNode *);
void InTracerseBTree(BTNode *);
void PostTracerseBTree(BTNode *);
int main(void)
{
    struct BTNode * pT = createBTree();
    printf("先序遍历\n");
    PreTracerseBTree(pT);
    printf("中序遍历\n");
    InTracerseBTree(pT);
    printf("后序遍历\n");
    PostTracerseBTree(pT);
    return 0;
}

struct BTNode * createBTree(void)
{
    struct BTNode * pA=(struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pB=(struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pC=(struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pD=(struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pE=(struct BTNode *)malloc(sizeof(struct BTNode));
    
    pA->data='A';
    pB->data='B';
    pC->data='C';
    pD->data='D';
    pE->data='E';

    pA->pLchild=pB;
    pA->pRchild=pC;
    pB->pLchild=pB->pRchild=NULL;
    pC->pLchild=pD;
    pC->pRchild=NULL;
    pD->pLchild=NULL;
    pD->pRchild=pE;
    pE->pLchild=pE->pRchild=NULL;
    
    return pA;
}
/**
 *先访问根节点，在访问左子树，再访问右子树
 **/
void PreTracerseBTree(struct BTNode * pT)
{
    
    if(pT!=NULL)
    {
        printf("%c\n",pT->data);
        PreTracerseBTree(pT->pLchild);
        PreTracerseBTree(pT->pRchild);
    }
    
    return;
}

void InTracerseBTree(struct BTNode * pT)
{
    
    if(pT!=NULL)
    {
        InTracerseBTree(pT->pLchild);
        printf("%c\n",pT->data);
        InTracerseBTree(pT->pRchild);
    }
    
    return;
}

void PostTracerseBTree(struct BTNode * pT)
{
        if(pT!=NULL)
    {
        PostTracerseBTree(pT->pLchild);
        PostTracerseBTree(pT->pRchild);
        printf("%c\n",pT->data);
    }
    
    return;
}
