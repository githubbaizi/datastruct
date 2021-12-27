/*
* 链式存储线性表
* 作者:黑白子
* 时间:2021-06-15
*/
#include "stdio.h"
#include "stdlib.h"
// 线性表的节点结构体
typedef struct {
    int data;//保存节点数据
    struct Node *next;//指向下一个节点
}Node;

// 获取元素个数
int getCount(Node *head)
{
    int count = 0;
    Node* p = head;//定义一个指针首先指向头结点
    while (p->next != NULL)//还有数据元素
    {
        count++;
        p = p->next;
    }
    return count;
}

// 显示所有元素
void printList(Node *head)
{
    int i;
    printf("\n所有元素:");
    Node* p = head;//定义一个指针首先指向头结点
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d ", p->data);
    }
}

// 获取指定位置元素，返回值放入result指向元素，注意位置从0开始
int getData(Node *head, int index, int *result)
{
    int i = 0;//当前位置
    if (index < 0)
    {
        return 0; //位置不存在
    }
    Node* p = head;//定义一个指针首先指向头结点

    while (p->next != NULL)
    {
        p = p->next;
        if (i == index) {
            *result = p->data;
        }
        i++;
    }
    if (i >= index) //位置超限
    {
        return 0;
    }
    return 1;//1表示成功
}

// 插入元素
int insertData(Node *head, int index, int input)
{
    int i = 0;//当前位置
    Node* temp = (Node*)malloc(sizeof(Node));//临时节点
    if (index < 0)
    {
        return 0; //位置不存在
    }
    if (index == 0) //第一个位置插入元素
    {
        temp->data = input;
        temp->next = head->next;
        head->next = temp;
        return 1;
    }
    Node* p = head;//定义一个指针首先指向头结点
    while (p->next != NULL)
    {
        p = p->next;
        i++;
        if (i == index) {//找到插入位置
            temp->data = input;
            temp->next = p->next;
            p->next = temp;
            return 1;
        }
    }
    if (i == index) //最后一个后面追加
    {
        return 1;
    }
    else {
        return 0;//位置超限
    }
    return 1;
}

// 删除指定位置元素
int deleteData(Node *head, int index)
{
    int i = 0;//当前位置
    if (index < 0)
    {
        return 0; //位置不存在
    }
    Node* p = head;//定义一个指针首先指向头结点
    Node* front = head;//记录前一个元素
    while (p->next != NULL)
    {
        front = p;
        p = p->next;
        if (i == index) {//删除该元素
            front->next = p->next;//跳过被删除元素
            free(p);//释放
            return 1;
        }
        i++;
    }
    if (i >= index) //位置超限
    {
        return 0;
    }
    return 1;//1表示成功
}

// 清空所有元素
int clearData(Node *head)
{
    Node* p = head->next;
    Node* temp;
    while (p != NULL)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
    head->next = NULL;
    return 1;
}

// 入口
int main()
{
    Node head;//头部节点实际上就代表了一个链表
    head.data = 0;//头部节点存储的数据没意义
    head.next = NULL;//刚开始没有数据节点
    int count = getCount(&head);
    printf("初始长度:%d\n", count);
    insertData(&head, 0, 1);
    insertData(&head, 1, 2);
    insertData(&head, 1, 3);
    count = getCount(&head);
    printf("新增后长度:%d\n", count);
    printList(&head);
    int result = 0;
    getData(&head, 2, &result);
    printf("位置2元素:%d\n", result);
    deleteData(&head, 0);
    printList(&head);
    clearData(&head);
    count = getCount(&head);
    printf("清空后长度:%d\n", count);
    return 1;
}


