#include<stdio.h>
#include"ListNode.h"
#include"Palindrome.h"
#include"reverseList.h"
int main(){
	
	int arr[10];
	int ch;
	listptr head;
	int count ;
	 
         		     count = 1;
                                int val = 0;
                                char c;
                                head = Create_head();
                                while(1){
                                        printf("输入要插入的第%d节点值\n", count);
                                        printf("如果输入的值是0，进一步选择插入还是退出\n");
                                        scanf("%d", &val);
                                        //去掉enter字符
                                        getchar();
                                        if(val == 0){
                                                printf("i 插入\t q 退出\n");
                                                scanf("%c", &c);
                                                printf("c = %c\n" ,c);
                                                if(c == 'q'){
                                                        break;
                                                }
                                        }
                                        Add_node(head, val);
                                        count++;
                                }
				

	while(1){
		printf("1.回文算法(Palindrome algorithm)\n");
		printf("2.LRU缓存算法实现\n");
		printf("3.反转链表算法\n");
		printf("选择想了解的算法\n");
		scanf("%d", &ch);	
	
	
	
		switch(ch){
			case 1:
				count = 1;
				int val = 0;
				char ch;
				head = Create_head();
				while(1){
					printf("输入要插入的第%d节点值\n", count);
					printf("如果输入的值是0，进一步选择插入还是退出\n");
					scanf("%d", &val);
					//去掉enter字符
					getchar();
					if(val == 0){
						printf("i 插入\t q 退出\n");
						scanf("%c", &ch);
						printf("ch = %c\n" ,ch);
						if(ch == 'q'){
							break;
						}
					}
					Add_node(head, val);
					count++;
				}
				Free_list(head);
				//Palindrome(head);
				break;	
			case 2:
				break;
			
			case 3:
				head =  reverseList(head);
				head = head + 1;
				printf("%p", head);
				while(head){
					printf("%d\n", head->val);
					head = head->next;
				}
				break;
		};
	}
	return 0;
}
