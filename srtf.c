#include <stdio.h>

int main() {
    int n, at[10], bt[10], rt[10], ct[10];
    int t = 0, done = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while (done < n) {
        int s = -1, mn = 9999;

        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && rt[i] < mn) {
                mn = rt[i];
                s = i;
            }
        }

        if (s == -1) {
            t++;
            continue;
        }

        rt[s]--;
        t++;

        if (rt[s] == 0) {
            ct[s] = t;
            done++;
        }
    }

    printf("Process\tCT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\n", i + 1, ct[i]);

    return 0;
}
