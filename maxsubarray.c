#include <stdio.h>

void maxSubArraySum(int a[], int size) {
    int dp[size];
    dp[0] = a[0];
    int ans = dp[0];

    for (int i = 1; i < size; i++) {
        dp[i] = (a[i] > a[i] + dp[i - 1]) ? a[i] : (a[i] + dp[i - 1]);
        ans = (ans > dp[i]) ? ans : dp[i];
    }

    printf("%d", ans);
}

int main() {
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);
    maxSubArraySum(a, n);
    return 0;
}
