#include<stdio.h>
struct Process {
    int pid; // Process ID
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};
void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
    }
}
void printProcesses(struct Process processes[], int n) {
    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }
}
void calculateAverages(struct Process processes[], int n) {
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        totalWT += processes[i].waitingTime;
        totalTAT += processes[i].turnaroundTime;
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
    }
    calculateTimes(processes, n);
    printProcesses(processes, n);
    calculateAverages(processes, n);

    return 0;
}