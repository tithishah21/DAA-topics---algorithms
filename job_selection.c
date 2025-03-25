#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
bool dfs(int* jobs, int* worker, int jobsSize, int workerSize, int step, int target) {
    if (step >= jobsSize) {
        return true;
    }

    int cur = jobs[step];
    for (int i = 0; i < workerSize; i++) {
        if (worker[i] + cur <= target) {
            worker[i] += cur;
            if (dfs(jobs, worker, jobsSize, workerSize, step + 1, target)) {
                return true;
            }
            worker[i] -= cur;
        }
        if (worker[i] == 0) {
            break;
        }
    }

    return false;
}

int minimumTimeRequired(int* jobs, int jobsSize, int k) {
    int sum = 0;
    for (int i = 0; i < jobsSize; i++) {
        sum += jobs[i];
    }

    qsort(jobs, jobsSize, sizeof(int), compare);

    int l = jobs[0], r = sum;
    while (l < r) {
        int mid = (l + r) / 2;

        int* worker = (int*)calloc(k, sizeof(int));
        if (dfs(jobs, worker, jobsSize, k, 0, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
        free(worker);
    }

    return l;
}

int main() {
    int n, k;
    scanf("%d", &n);

    int* jobs = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &jobs[i]);
    }
    scanf("%d", &k);
    int result = minimumTimeRequired(jobs, n, k);
    printf("%d", result);

    free(jobs);
    return 0;
}
