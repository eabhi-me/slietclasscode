#include <stdio.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int isCompleted; 
};

int main() {
    int n, time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", p[i].id);
        scanf("%d %d", &p[i].arrivalTime, &p[i].burstTime);
        p[i].isCompleted = 0;
    }

    while (completed != n) {
        int idx = -1, minBT = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].arrivalTime <= time && !p[i].isCompleted && p[i].burstTime < minBT) {
                minBT = p[i].burstTime;
                idx = i;
            }
        }

        if (idx != -1) {
            time += p[idx].burstTime;
            p[idx].completionTime = time;
            p[idx].turnaroundTime = p[idx].completionTime - p[idx].arrivalTime;
            p[idx].waitingTime = p[idx].turnaroundTime - p[idx].burstTime;
            p[idx].isCompleted = 1;
            completed++;
        } else {
            time++; // Idle time
        }
    }

    float totalWT = 0, totalTAT = 0;
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        totalWT += p[i].waitingTime;
        totalTAT += p[i].turnaroundTime;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrivalTime, p[i].burstTime, p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
    }

    printf("Average Waiting Time = %.2f\n", totalWT / n);
    printf("Average Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}