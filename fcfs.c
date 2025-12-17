#include <stdio.h>

int main() {
    int n, at[10], bt[10], ct[10], tat[10], wt[10];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0;i < n;i++) {
        printf("Enter AT and BT of P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }

    ct[0] = at[0] + bt[0];
    for (int i = 1;i < n;i++)
        ct[i] = ct[i - 1] + bt[i];

    for (int i = 0;i < n;i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nProcess AT BT CT TAT WT\n");
    for (int i = 0;i < n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
            i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\nAverage WT = %.2f", avgwt / n);
    printf("\nAverage TAT = %.2f\n", avgtat / n);
}
