#include <stdio.h>
#include <string.h>
int max(int x,int y){
    return x>y?x:y;
}
int lcsRec(char s1[],char s2[],int m,int n){
    if(m==0 || n==0){
        return 0;
    }
    if(s1[m-1]==s2[n-1]){
        return 1+lcsRec(s1,s2,m-1,n-1);
    }
    else{
        return max(lcsRec(s1,s2,m,n-1),lcsRec(s1,s2,m-1,n));
    }
}
int lcs(char s1[],char s2[]){
    int m = strlen(s1);
    int n = strlen(s2);
    return lcsRec(s1,s2,m,n);
}
int main(){
    char s1[]="qwertyu";
    char s2[]="qwertyuio";
    printf("%d",lcs(s1,s2));
    return 0;
}