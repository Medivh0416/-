//
//  快速排序.cpp
//  数据结构
//
//  Created by Xuchu on 15/12/24.
//  Copyright © 2015年 Xuchu. All rights reserved.
//

#include <stdio.h>

int FindPos(int * a,int low,int high)
{
    int val=a[low];
    while (low<high)
    {
        while (low<high && a[high]>=val)
        {
            high--;
        }
        
        a[low]=a[high];
        while (low<high && a[high]<=val)
        {
            low++;
        }
        
        a[high]=a[low];
    }
    a[low]=val;
    return low; //这里返回的是位置
}

void QuickSort(int * a,int low,int high)
{
    int pos;
    if (low<high)
    {
        pos=FindPos(a,low,high);
        QuickSort(a,low, pos-1);
        QuickSort(a,pos+1, high);
    }
}
int main(void)
{
    int a[6]={2,-1,0,5,-4,3};
    int i;
    QuickSort(a,0,5);   //第二个参数表示第一个元素的下标，第二个参数表示最后一个元素的下标
    
    for(i=0;i<6;i++)
    {
        printf("%d  ",a[i]);
    }
    return 0;
}