//
//  递归.cpp
//  数据结构
//
//  Created by Xuchu on 15/12/22.
//  Copyright © 2015年 Xuchu. All rights reserved.
//

# include <stdio.h>
/**
 *求阶乘
 **/
long jiecheng(long n)
{
    if (n==1) {
        return 1;
    }
    else
        return jiecheng(n-1)*n;
}
/**
 *1到N相加
 **/
long jia(long n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return jia(n-1)+n;
    }
}

/**
 *汉诺塔
 *如果是一个盘子，直接讲A柱子上的盘子从A移到C
 *否则，鲜姜A柱子上的n－1个盘子接住C移到B
 *直接将A柱子上的盘子从A移到C
 *最后将B柱子上的n－1个盘子接住A移到C
 **/

void hannuota(int n,char x,char y,char z)
{
    if (n==1)
    {
        printf("将编号为%d的盘子从%c的柱子移到%c的柱子\n",n,x,z);
    }
    else
    {
        hannuota(n-1, x, z, y);
        printf("将编号为%d的盘子从%c的柱子移到%c的柱子\n",n,x,z);
        hannuota(n-1, y, x, z);
    }
}

int main(void)
{
    int n=21;
    char ch1='X';
    char ch2='Y';
    char ch3='Z';
    hannuota(n,ch1,ch2,ch3);
}
