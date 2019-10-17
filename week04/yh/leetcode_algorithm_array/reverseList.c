#include"ListNode.h"
#include<stdlib.h>
#include<stdio.h>
struct ListNode* reverseList(struct ListNode* head){
    //保存下一个节点
    struct ListNode *p;
    //递归结束条件
    if(head == NULL || head->next == NULL){
	printf("head1 = %p\n", head);
	return head;
    }
/*
   //递归
    reverseList(head->next);
    //初始化p    
    p = head->next;
    //反转
    p->next = head;
    head->next = NULL;
*/
    p =  reverseList(head->next);
    
	head->next->next = head;
    //反转
    head->next = NULL;
	return p;
}

/*
1.第一种为什么不可以
2.返回值p有什么作用
3.地址结果为什么还加1
4.不用递归自己怎么实现
5.不用递归的标准答案
*/
