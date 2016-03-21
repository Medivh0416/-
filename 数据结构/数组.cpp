//
//  main.cpp
//  数据结构
//
//  Created by Xuchu on 15/12/19.
//  Copyright © 2015年 Xuchu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//定义了一个数据类型，该数据类型的名字叫做struct arr
struct Arr
{
    int * pBase; //第一个元素的地址
    int len;
    int count;
};

void init_arr(struct Arr * pArr,int length);
bool append_arr(struct Arr * pArr,int val);
bool insert_arr(struct Arr * pArr,int pos,int val); //pos的值从一开始，指下标
bool delete_arr(struct Arr * pArr,int pos,int *pval);
int get();
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr);

int main(void)
{
    struct Arr arr;
    int val;
    
    init_arr(&arr,6);
    append_arr(&arr, 11);
    append_arr(&arr, 2);
    append_arr(&arr, -1);
    append_arr(&arr, 4);
    insert_arr(&arr, 2, 6);
    delete_arr(&arr, 3,&val);
    show_arr(&arr);
    inversion_arr(&arr);
    show_arr(&arr);
    sort_arr(&arr);
    show_arr(&arr);
    return 0;
}

void init_arr(struct Arr * pArr,int length)
{
    pArr->pBase = (int *)malloc(sizeof(int)*length);
    if(NULL == pArr->pBase)
    {
        printf("动态内存分配失败");
        exit(-1);
    }
    else
    {
        pArr->len=length;
        pArr->count=0;
    }
    return;
}

bool is_empty(struct Arr * pArr)
{
    if (0 == pArr->count)
    {
        return true;
    }
    else
        return false;
}
bool is_full(struct Arr * pArr)
{
    if (pArr->len==pArr->count)
    {
        return true;
    }
    else
        return false;
    
}

void show_arr(struct Arr * pArr)
{
    if (is_empty(pArr))
    {
        printf("数组为空");
    }
    else
    {
        for (int i=0; i<pArr->count; i++)
        {
            printf("%d ",pArr->pBase[i]);
        }
    }
    printf("\n");
    
}

bool append_arr(struct Arr * pArr,int val)
{
    if (is_full(pArr))
    {
        printf("数字%d插入失败\n",val);
        return false;
    }
    
    pArr->pBase[(pArr->count)]=val;
    (pArr->count)++;
    return true;
}

bool insert_arr(struct Arr * pArr,int pos,int val)
{
    if (is_full(pArr))
    {
        return false;
    }
    
    if (pos<1 || pos>pArr->count+1)
    {
        printf("输入POS错误");
        return false;
    }
    
    for (int i=pArr->count-1; i>=pos-1; i--)
    {
        pArr->pBase[i+1]=pArr->pBase[i];
    }
    pArr->pBase[pos-1]=val;
    pArr->count++;
    return true;
}

bool delete_arr(struct Arr * pArr,int pos,int * pavl)
{
    if (is_empty(pArr))
    {
        return false;
    }
    if (pos<1 || pos>pArr->count+1)
    {
        printf("输入POS错误");
        return false;
    }
    
    *pavl=pArr->pBase[pos-1];
    
    for (int i=pos; i<pArr->count; i++)
    {
        pArr->pBase[i-1]=pArr->pBase[i];
    }
    pArr->count--;
    printf("删除%d\n",*pavl);
    return true;
}

void inversion_arr(struct Arr * pArr)
{
    int i=0;
    int j=pArr->count-1;
    int t;
    while (i<j) {
        t=pArr->pBase[i];
        pArr->pBase[i]=pArr->pBase[j];
        pArr->pBase[j]=t;
        i++;
        j--;
    }
}

void sort_arr(struct Arr * pArr)    //冒泡
{
    int i,j,t;
    
    for (i=0; j<pArr->count; i++)
    {
        for (j=i+1; j<pArr->count; j++)
        {
            if (pArr->pBase[i]>pArr->pBase[j])
            {
                t=pArr->pBase[i];
                pArr->pBase[i]=pArr->pBase[j];
                pArr->pBase[j]=t;
            }
        }
    }
}