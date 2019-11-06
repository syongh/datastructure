#include<stdio.h>

int main(){
	int a[7] = {3, 11, 24, 49, 60, 66,71};
	int num = 71;
	int low, high, mid, b, k;
	low = 0;
	high = 6;
	//mid = (low+high)/2;
	mid = low + (num-a[low])/(a[high]-a[low])*(high - low);
	while(high >= low){
//	while(high > low){
//	while(high <= low){
		if(a[mid] == num){
			/*
			//实现查找多个相同的值
			b = mid – 1;
			k = mid – 1;
			while(a[b] == key)
			{
				printf(“%d的位置为%d\n”,key,b);
				b--;
			}
			while(a[k] == key)
			{
				printf(“%d的位置为%d\n”,key,k);
				k++;
			}
			*/
			printf("mid = %d   a[mid] = %d\n",mid,  a[mid]);
			return 0;
		}
		else if(a[mid] > num){
			high = mid-1;
		}		
		else{
			low = mid+1;
		}
		mid = low + (num-a[low])/(a[high]-a[low])*(high - low);
	}
		
}

/*
如何查找数组里面有值相等的情况
记时第一次完成，第n次完成情况
*/
