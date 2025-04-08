#include <stdio.h>
#include <string.h>

void naiveSearch(char txt[], char pat[]) {
    int n = strlen(txt);
    int m = strlen(pat);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == m) {
            printf("%d %d\n", i + 1, i + m);
        }
    }
}

int main() {
    char txt[55];
    char pat[30];

    printf("Enter text: ");
    scanf("%s", txt);

    printf("Enter pattern: ");
    scanf("%s", pat);

    naiveSearch(txt, pat);

    return 0;
}
