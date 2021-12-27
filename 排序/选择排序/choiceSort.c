#include <stdio.h>
#include <stdlib.h>
void choiceSort(int *arr[]){
    int t=0;
    for(int i = 0; i < 10; i++) {
        int index=i;
        for(int j=i+1;j<10;j++){
            if(arr[index]>arr[j])
            {
                index=j;
                // 交换两个数
                if(index!=i){
                    t=arr[i];
                    arr[i]=arr[index];
                    arr[index]=t;
                }
            }
        }
    }
}
int main()
{
    int *a[]={1,2,3,5,4,9,7,8,6,4};
    choiceSort(&a); 
    printf("打印遍历好的数据");
    int i;
    for(i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
