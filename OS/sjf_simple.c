#include <stdio.h>

void sortProcesses(int n, int bt[], int p[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst times
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process IDs
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void calculateTimes(int n, int bt[], int wt[], int tat[]) {
    wt[0] = 0; // Waiting time for first process is 0
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
}

void printResults(int n, int p[], int bt[], int wt[], int tat[]) {
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], wt[n], tat[n];

    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1; // Process IDs
    }

    sortProcesses(n, bt, p);
    
    calculateTimes(n, bt, wt, tat);

    // Calculate average waiting time and turnaround time
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    calculateTimes(n, bt, wt, tat);
    printResults(n, p, bt, wt, tat);

    return 0;
}