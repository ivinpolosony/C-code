#include <stdio.h>
	
void display(int arr[] ,int size){
	printf("------DISPLAY ----\n");
	for (int i = 0; i < size; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
<<<<<<< HEAD
void quick_sort_divide(int arr[] ,int start ,int end ){
	int pivot_index,temp,i,j;
	if(start<end){
		pivot_index = start;
		i = start;
		j = end;
		for(;i<j;){
			for( ;arr[i]<=arr[pivot_index] && i < end; ){
				i++;
			}
			for( ;arr[j]>arr[pivot_index];){
				j--;
			}
			if(i<j){
				temp = arr[i];
				arr[i]=arr[j];
				arr[j] = arr[i];
			}				
		}
			temp = arr[pivot_index];
			arr[pivot_index] = arr[j];
			arr[j]=temp;
			quick_sort_divide(arr,start,pivot_index);
   			quick_sort_divide(arr,pivot_index + 1 , end );
	}
=======
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
>>>>>>> 5de7fcf5583ff154a0e6af2bc8011c5b784cf545
}


int main(int argc, char const *argv[]){
	int arrNum[] = {7,2,8,5,4,1};
    int count = sizeof arrNum / sizeof arrNum[0];
<<<<<<< HEAD
    quick_sort_divide(arrNum, 0 ,sizeof(arrNum)/sizeof(int));
	display(arrNum,count);
=======
    quick_sort_divide(arrNum, sizeof(arrNum)/sizeof(int));
>>>>>>> 5de7fcf5583ff154a0e6af2bc8011c5b784cf545
	return 0;

}
