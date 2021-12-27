#include <stdio.h>
#include <stdlib.h>
// 从当前的i位向前找，如果比前一个小，就交换位置
int main()
{
    int a[]={49,38,65,97,76,13,27,49};
    int length=sizeof(a)/sizeof(a[0]);
    printf("打印数组长度%d\n",length);
    int i,j,t=0;
    
    for(i=1;i<length;i++)
        for(j=i;j>0;j--){
            if(a[j]<a[j-1]){
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }
        }
    
 
    
    // 打印数组
    for (i = 0; i < length; i++) {
        printf("%d ",a[i]);
    }
    return 0;
}
