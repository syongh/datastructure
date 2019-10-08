#include<stdio.h>

int main(){
	int k = 0;
	int arr[3] = {0};
	int b[3] = {0};
	int i = 0;
	int j = 0;
	printf("i = %p \n", &i);
	printf("j = %p \n", &j);
	printf("k = %p \n", &k);
	printf("arr[0] = %p \n", &arr[0]);
	printf("arr[2] = %p \n", &arr[2]);
	printf("b[2] = %p \n", &b[0]);
	printf("b[2] = %p \n", &b[2]);
	
	for(; i <= 3; i++){
		arr[i] = 0;
		printf("hello world!\n");
	}
	return 0;
}
