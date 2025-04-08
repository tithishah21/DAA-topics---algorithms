#include <stdio.h>

typedef struct {
    int x, y;
} Point;

int main() {
    int n;
    scanf("%d", &n);

    if (n < 3) {
        printf("Convex hull not possible with less than 3 points\n");
        return 0;
    }

    Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    Point leftmost = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].x < leftmost.x || (points[i].x == leftmost.x && points[i].y < leftmost.y)) {
            leftmost = points[i];
        }
    }

    printf("%d %d\n", leftmost.x, leftmost.y);
    return 0;
}

