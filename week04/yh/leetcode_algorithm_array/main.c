#include<stdio.h>
#include"ListNode.h"
#include"Palindrome.h"
int main(){
	
	int arr[10];
	int ch;
				listptr head;
				int count ;
	while(1){
		printf("1.回文算法(Palindrome algorithm)\n");

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
				break;	
		};
		Palindrome(head);
	}
	return 0;
}
