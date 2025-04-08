#include <stdio.h>
int knapsack(int W,int wt[],int value[],int n){
    if(W==0||n==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(W,wt,value,n-1);
    }
    else{
        int include = value[n-1]+knapsack(W-wt[n-1],wt,value,n-1);
        int exclude = knapsack(W,wt,value,n-1);
        return(include>exclude)?include:exclude;
    }
}
int main(){
    int W = 60;
    int wt[]={10,20,30,40,30,80};
    int value[]={1,2,3,4,5,6};
    int n=sizeof(value)/sizeof(value[0]);
    printf("%d",knapsack(W,wt,value,n));
}