#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

void sortByBurstTime(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].burstTime > p[j].burstTime) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void calculateTimes(struct Process p[], int n) {
    p[0].waitingTime = 0;
    p[0].turnaroundTime = p[0].burstTime;

    for (int i = 1; i < n; i++) {
        p[i].waitingTime = p[i - 1].waitingTime + p[i - 1].burstTime;
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
    }
}

void display(struct Process p[], int n) {
    printf("ID\tBurst\tWaiting\tTurnaround\n");
    float totalWaiting = 0, totalTurnaround = 0;
    for (int i = 0; i < n; i++) {
        totalWaiting += p[i].waitingTime;
        totalTurnaround += p[i].turnaroundTime;
        printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].burstTime, p[i].waitingTime, p[i].turnaroundTime);
    }
    printf("Average Waiting Time = %.2f\n", totalWaiting / n);
    printf("Average Turnaround Time = %.2f\n", totalTurnaround / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p[i].burstTime);
    }

    sortByBurstTime(p, n);
    calculateTimes(p, n);
    display(p, n);

    return 0;
}