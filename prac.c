#include <stdio.h>
#include <string.h>

int lcsRec(char s1[],char s2[],int m,int n){
    if(m==0 || n==0){
        return 0;
    }
    if(s1[m-1]==s2[n-1]){
        return 1+lcsRec(s1,s2,m-1,n-1);
    }
    else{
        return(lcsRec(s1,s2,m-1,n)>lcsRec(s1,s2,m,n-1))?lcsRec(s1,s2,m-1,n):lcsRec(s1,s2,m,n-1);
    }
}   
int lcs(char s1[],char s2[]){
    int m=strlen(s1);
    int n=strlen(s2);
    return lcsRec(s1,s2,m,n);
}
int main(){
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    char s1[n1];
    char s2[n2];
    printf("Enter chars for s1");
    for(int i = 0; i < n1;i++){
        scanf("%c",&s1[i]);
    }
    printf("Enter chars for s2");
    for(int i = 0; i < n2;i++){
        scanf("%c",&s2[i]);
    }
    printf("%d",lcs(s1,s2));
    return 0;
}