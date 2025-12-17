#include <stdio.h>

int main() {
    int n, t = 0, done = 0;
    int bt[10], at[10], pr[10], ct[10], tat[10], wt[10], comp[10] = { 0 };

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &bt[i], &at[i], &pr[i]);

    while (done < n) {
        int idx = -1, minp = 9999;

        for (int i = 0; i < n; i++)
            if (at[i] <= t && !comp[i] && pr[i] < minp)
                minp = pr[i], idx = i;

        if (idx == -1) { t++; continue; }

        t += bt[idx];
        ct[idx] = t;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        comp[idx] = 1;
        done++;
    }

    printf("PID BT AT PR CT TAT WT\n");
    for (int i = 0; i < n; i++)
        printf("P%d  %d  %d  %d  %d  %d  %d\n",
            i + 1, bt[i], at[i], pr[i], ct[i], tat[i], wt[i]);

    return 0;
}
