#include<stdio.h>

struct processes{
    int pid;
    int arrivalTime;
    int brustTime;
    int turnAroundTime;
    int completionTime;
    int waitingTime;
};

void calcAllTime(struct processes process[], int n){
    int currentTime = 0;
    for(int i=0; i<n; i++){
        if(currentTime<process[i].arrivalTime){
            currentTime = process[i].arrivalTime;
        }
        process[i].waitingTime = currentTime-process[i].arrivalTime;
        process[i].turnAroundTime = process[i].waitingTime + process[i].brustTime;
        process[i].completionTime = currentTime;
        currentTime += process[i].brustTime;
    }
}

void printTime(struct processes process[], int n){
    printf("PID\tArrival\tBurst\tcompletion\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", process[i].pid, process[i].arrivalTime,
               process[i].brustTime, process[i].completionTime, process[i].waitingTime, process[i].turnAroundTime);
    }
    printf("Average waiting Time");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct processes process[n];

    for (int i = 0; i < n; i++) {
        process[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &process[i].arrivalTime, &process[i].brustTime);
    }

    calcAllTime(process, n);
    printTime(process, n);

    return 0;
}