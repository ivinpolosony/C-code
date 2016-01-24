#include <stdio.h>
<<<<<<< HEAD
#include <iostrem.h>
=======
	
>>>>>>> 997bfa466987429401d2344a955b33d1108826fa
void display(int arr[] ,int size){
	printf("------DISPLAY ----\n");
	for (int i = 0; i < size; i++){
		printf("%d\t",arr[i]);
	}
	
}
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
<<<<<<< HEAD
    

	display(right,size);	
=======
>>>>>>> 997bfa466987429401d2344a955b33d1108826fa
}


int main(int argc, char const *argv[]){
    int arrNum[] = {7,2,8,5,4,1};
    int count = sizeof arrNum / sizeof arrNum[0];
<<<<<<< HEAD
    quick_sort_divide(arrNum, sizeof(arrNum)/sizeof(int));
    return 0;
	
=======
    quick_sort_divide(arrNum, 0 ,sizeof(arrNum)/sizeof(int));
	display(arrNum,count);
	return 0;

>>>>>>> 997bfa466987429401d2344a955b33d1108826fa
}
