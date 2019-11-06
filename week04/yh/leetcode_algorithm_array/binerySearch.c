#include<stdio.h>

int main(){
	int a[7] = {3, 11, 24, 49, 60, 66,71};
	int num = 3;
	int low, high, mid;
	low = 0;
	high = 6;
	mid = (low+high)/2;
	while(high >= low){
//	while(high > low){
//	while(high <= low){
		if(a[mid] == num){
			printf("mid = %d   a[mid] = %d\n",mid,  a[mid]);
			return 0;
		}
		else if(a[mid] > num){
			high = mid-1;
		}		
		else{
			low = mid+1;
		}
		mid = (high + low)/2;
	}
		
}

/*
如何查找数组里面有值相等的情况
记时第一次完成，第n次完成情况
*/
