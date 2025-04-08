#include <stdio.h>
typedef struct{
    int x,y;
}Point;
int main(){
    int n;
    scanf("%d",&n);
    if(n<3){
        return 0;
    }
    Point points[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&points[i].x,&points[i].y);
    }
    Point leftmost=points[0];
    for(int i=1;i<n;i++){
        if(points[i].x<leftmost.x){
            leftmost=points[i];
        }
    }
    printf("%d %d",leftmost.x,leftmost.y);
    return 0;
}