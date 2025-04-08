#include <stdio.h>
#include <string.h>

void naiveSearch(char txt[], char pat[]) {
    int n = strlen(txt);
    int m = strlen(pat);

    for (int i = 0; i <= n - m; i++) {
        int j;

        // Check for pattern match starting at position i
        for (j = 0; j < m; j++) {
            if (txt[i + j] != pat[j])
                break;
        }

        // If full pattern matched
        if (j == m) {
            // Output 1-indexed start and end indices
            printf("%d %d\n", i + 1, i + m);
        }
    }
}

int main() {
    char txt[55], pat[30];

    // Read full lines (to handle commas, spaces, etc.)
    fgets(txt, sizeof(txt), stdin);
    fgets(pat, sizeof(pat), stdin);

    // Remove trailing newline if any
    txt[strcspn(txt, "\n")] = '\0';
    pat[strcspn(pat, "\n")] = '\0';

    naiveSearch(txt, pat);

    return 0;
}
