//冒泡算法
void bubble_sort(int *arr){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j > 9-i; j++){
			if(arr[j] > arr[j+1]){
				arr[j] = arr[j]^arr[j+1];
				arr[j+1] = arr[j+1]^arr[j];
				arr[j]  = arr[j]^arr[j+1];	
			}
		}
	}
}
