#include <stdio.h>

void roundRobin(int processes[], int n, int burstTime[], int quantum) {
    int remainingTime[n];
    int waitingTime[n], turnAroundTime[n];
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }

    int time = 0;
    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = 0;

                if (remainingTime[i] > quantum) {
                    time += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    time += remainingTime[i];
                    waitingTime[i] = time - burstTime[i];
                    remainingTime[i] = 0;
                }
            }
        }

        if (done == 1) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }

    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnAroundTime / n);
}

int main() {
    int n, quantum;
 
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n];

    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    roundRobin(processes, n, burstTime, quantum);

    return 0;
}