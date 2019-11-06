#include<stdio.h>

int main(){
	int a[7] = {60, 71, 49, 11, 24, 3, 66};
	int temp = 0;
	int j;
	for(int i = 1; i < 7; i++){
		temp = a[i];
		for(j=i-1; j>=0; j--){	
			if(temp < a[j]){
				a[j+1] = a[j];
				continue;
			}
			break;
		}
		a[j+1] = temp;
	}
	for(int i=0; i < 7; i++){
		printf("%d  ", a[i]);
	}
	printf("\n");
}
