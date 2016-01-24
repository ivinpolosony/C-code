#include <stdio.h>
#Author:Ivin 
void insertion_sort (int *a, int n) {
    int i, j, temp;
    // for (i = 1; i < n; i++) {
    //     t = a[i];
    //     for (j = i; j > 0 && t < a[j - 1]; j--) {
    //         a[j] = a[j - 1];
    //     }
    //     a[j] = t;
    // }
    
    for(i = 0; i < n; i++){
        if(a[i] > a[i+1] ){
            temp = a[i+1];
            a[i+1] = a[i];
            a[i] = temp; 
         }
    }

    for ( i = 0; i < n; ++i){
        printf("%d\n",a[i] );
    }
    
}
 
int main () {
    int arrNum[] = {7,2,8,5,4};
    int n = sizeof arrNum / sizeof arrNum[0];
    int i;
    //Before 
    // for (i = 0; i < n; i++)
    //     printf("%d", arrNum[i]);
    insertion_sort(arrNum, n); 
    // After 
    // for (i = 0; i < n; i++)
    //     printf("%d", arrNum[i]);
    return 0;
    
}
   
