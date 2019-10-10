#include "ListNode.h"
#include <stdlib.h>
//#include <stdlib.h> //如果不加上这个头文件
#include <stdio.h>

listptr Create_head(){
	listptr head = (listptr)malloc(sizeof(list));
	printf("create list success\n");
	head->next = NULL;
	head->val = 0;
	return head;
}
//释放链表
void Free_list(listptr head){
	listptr temp;
	if(head->next == NULL){
		free(head);
		printf("free the only node head\n");
	}
	else{
		while(head->next != NULL){
			temp = head;
			head = head->next;
			free(temp);
			printf("free all the list nodes\n");
		}
	}
}

//头插法
void Add_node(listptr head, int val){

        listptr node = (listptr)malloc(sizeof(list));
        if(node == NULL){
                printf("fail to malloc a list node\n");     
                return ;
        }
        if(head->next == NULL){
                head->next = node;
                node->next = NULL;
                node->val = val;
		printf("ok! insert a list node for an empty head\n");
        }
        else{
                node->next = head->next;
                node->val = val;
                head->next = node;
		printf("ok! insert a list node\n");
        }
}

