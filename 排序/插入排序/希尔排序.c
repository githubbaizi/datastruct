#include <stdio.h>
#include <stdlib.h>
// 从当前的i位向前找，如果比前一个小，就交换位置
int main()
{
    int a[]={49,38,65,97,76,13,27,49};
    int length=sizeof(a)/sizeof(a[0]);
    printf("打印数组长度%d\n",length);
    int i,j,t=0;
    int k;//用来记录下表，最小数的
    
    int step=length/2;
    for(;step>0;step/=2){
        for(i=step;i<length;i++){
            int value=a[i];
            int j;
            for(j=i-step;j>=0&&a[j]>value;j-=step)
                a[j+step]=a[j];
            a[j+step]=value;
        }
    }
    
    
    // 打印数组
    for (i = 0; i < length; i++) {
        printf("%d ",a[i]);
    }
    return 0;
}
