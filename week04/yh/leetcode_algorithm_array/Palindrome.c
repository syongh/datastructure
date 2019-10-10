//快慢指针实现回文算法

/*
思路：

使用快慢两个指针找到链表中点，慢指针每次前进一步，快指针每次前进两步。在慢指针前进的过程中，同时修改其 next 指针，使得链表前半部分反序。最后比较中点两侧的链表是否相等。
*/
#include<stdio.h>

void Palindrome(listptr head){
	listptr fast = head;
	
	int count = 0;
	
	if(head->next == NULL){
		printf("the list only head\n");
		return ;
	}
	
	listptr slow = head->next;
	listptr p = slow->next;
	listptr q = q->next;
	
	while(slow->next != NULL){
		slow  = slow->next;
		count++;
	}
	slow = head;
	printf("the list node's count = %d\n", count);

	while(fast->next->next != NULL){
		printf("")
		//未破坏链表结构前操作	
		fast = fast->next->next;
	
		//反转
		p->next = slow;
		//移动指针
		slow = p;
		p = q;
		if(q->next != NULL){
			q = q->next;
		}
		else{
			printf("q 的下一个节点是NULL, 也就是反转结束了\n");
			break;
		}	
	}
	//输出结果
	

}
