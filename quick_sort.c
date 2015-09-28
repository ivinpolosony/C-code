#include <stdio.h>

void display(int arr[] ,int size){
	printf("------DISPLAY ----\n");
	for (int i = 0; i < size; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
void quick_sort_divide(int arr[] ,int size ){
	int pivot_index = size-1;
	int left[size/2] , right[size/2] ,i , j=0 ,k=0;

	for(i = 0 ; i <= pivot_index-1 ; i++){
		if(arr[i] < arr[pivot_index]){
			 
		}else{
			right[k++] = arr[i];
			printf("%d\n",arr[i] ); 

		}
	}

	display(right,size);	
}
int main(int argc, char const *argv[]){
	int arrNum[] = {7,2,8,5,4,1};
    int count = sizeof arrNum / sizeof arrNum[0];
    quick_sort_divide(arrNum, sizeof(arrNum)/sizeof(int));
	return 0;

}
