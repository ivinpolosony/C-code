#include <stdio.h>

int  main(int argc, char const *argv[])
{
	int arrNum[] = {7,2,8,5,4,1};
    int count = sizeof arrNum / sizeof arrNum[0];
    int i,j,temp;

    for ( i = 0; i < count; i++){
    	for (j = 0; j < count; j++){
    		if(arrNum[i] < arrNum[j] ){
    			temp = arrNum[j];
    			arrNum[j] = arrNum[i];
    			arrNum[i] = temp; 
    		}
    	}
    }

    for ( i = 0; i < count; i++){
    	printf("%d\t",arrNum[i] );
    }
	return 0;
}