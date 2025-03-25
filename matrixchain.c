#include <limits.h>
#include <stdio.h>
//i = index of 1st matrix
//j=index of last matrix
int MatrixChainOrder(int p[],int i,int j){
    if(i==j){
        return 0;
    }
    //Loop variable to split the matrix chain.
    int k;

    //Stores the minimum number of multiplications
    int min=INT_MAX;

    //Stores the current multiplication cost for a particular split.
    int count;

    //k is the split point for dividing 2 matrices, one matrix from i to k and other from k+1 to j
    for(k=i;k<j;k++){
        count=MatrixChainOrder(p,i,k)+MatrixChainOrder(p,k+1,j)+p[i-1]*p[k]*p[j];
        if(count<min){
            min=count;
        }
    }
    return min;
}

int main(){
    //supposing that A1 has dimn 1x2, A2 has 2x3 etc
    int arr[]={1,2,3,4,3};
    int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	printf("Minimum number of multiplications is %d ",
		MatrixChainOrder(arr, 1, N - 1));
	getchar();
	return 0;
}