#include<stdio.h>
#include"sort.h"
int main(){
	
	int arr[10] = {0};
	int ch;
	while(1){
		printf("1.冒泡算法\n");

		printf("选择排序算法\n");
		scanf("%d", &ch);	
	
		printf("输入需要排序的10个数\n");
	
		for(int i = 0; i < 10; i++){
			scanf("%d",&arr[i]);
		}
	
		switch(ch){
			case 1:
				bubble_sort(arr);
				break;	
		};

		for(int i = 0; i < 10; i++)
			printf("%d  ",arr[i]);
	}

}
