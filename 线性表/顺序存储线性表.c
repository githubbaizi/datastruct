 
 /*
* 顺序存储线性表
* 作者:黑白子
* 时间:2021-06-15
*/
#include<stdio.h>
#define MAXSIZE 100 //最大元素个数

// 线性表的结构体
typedef struct {
    int data[MAXSIZE];
    int count;//当前元素个数
}SequenceList;

// 获取元素个数
int getCount(SequenceList *list)
{
    return list->count;
}

// 显示所有元素
void printList(SequenceList *list)
{
    int i;
    printf("\n所有元素:");
    for (i = 0; i < list->count; i++)
    {
        printf("%d", list->data[i]);
    }
}

// 获取指定位置元素，返回值放入result指向元素
int getData(SequenceList *list, int index, int *result)
{
    if (index<0 || index>list->count - 1)
    {
        return 0;//0表示失败
    }
    *result = list->data[index];
    return 1;//1表示成功
}

// 插入元素
int insertData(SequenceList *list, int index, int input)
{
    int i;
    if (list->count >= MAXSIZE) //满了
    {
        return 0;
    }
    if (index<0 || index>list->count) //不在合理范围
    {
        return 0;
    }
    if (index != list->count) //插入数据不在表尾
    {
        for (i = list->count; i >= index; i--)
        {
            list->data[i] = list->data[i - 1];
        }
    }
    list->data[index] = input;
    list->count++;
    return 1;
}
// 删除指定位置元素
int deleteData(SequenceList *list, int index)
{
    int i;
    if (index<0 || index>list->count - 1) //不在合理范围
    {
        return 0;
    }
    for (i = index; i < list->count - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->count--;
    return 1;
}
// 清空所有元素
int clearData(SequenceList *list)
{
    list->count = 0;
}

// 程序入口
int main()
{
    //初始化
    SequenceList sequenceList;
    SequenceList *list = &sequenceList;
    list->count = 0;
    //插入元素
    insertData(list, 0, 1);
    insertData(list, 1, 2);
    insertData(list, 2, 3);
    printList(list);
    //获取元素
    int result = -1;
    getData(list, 1, &result);
    printf("\ngetData:%d", result);
    //删除指定位置元素
    deleteData(list, 1);
    printList(list);
    //清空元素
    clearData(list);
    printList(list);
    printf("\n");
    return 1;
}

