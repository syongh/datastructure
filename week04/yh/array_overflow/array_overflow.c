#include<stdio.h>

int main(){
	int i = 0;
	int arr[3] = {0};
	printf("i = %p \n", &i);
	printf("arr[0] = %p \n", &arr[0]);
	printf("arr[2] = %p \n", &arr[2]);
	
	for(; i <= 3; i++){
		arr[i] = 0;
		printf("hello world!\n");
	}
	return 0;
}
