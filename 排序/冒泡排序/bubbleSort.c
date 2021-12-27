// 冒泡排序
/*
冒泡排序的原理是：从左到右，相邻元素进行比较。每次比较一轮，
就会找到序列中最大的一个或最小的一个。这个数就会从序列的最右边冒出来。
每执行一次i 就会有一个排序好的数放在最后边所以 length-i 
-1是为了防止下标越界
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[]={1,2,4,3,6,5,8,7,9};
    int length=sizeof(a)/sizeof(a[0]);
    printf("打印数组长度%d\n",length);
    int i,j,t=0;
    for ( i = 0; i < length-1; i++) {
        for ( j = 0; j < length-i-1; j++) {
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    // 打印数组
    for (i = 0; i < length; i++) {
        printf("%d ",a[i]);
    }
    return 0;
}
