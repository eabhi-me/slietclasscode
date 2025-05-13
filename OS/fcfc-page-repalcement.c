#include <stdio.h>

void FCFS_PageReplacement(int pages[], int n, int capacity) {
    int frames[capacity], front = 0, pageFaults = 0;
    for (int i = 0; i < capacity; i++) frames[i] = -1;

    printf("Page Reference\tFrames\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) if (frames[j] == pages[i]) found = 1;

        if (!found) {
            frames[front] = pages[i];
            front = (front + 1) % capacity;
            pageFaults++;
        }

        printf("%d\t\t", pages[i]);
        for (int j = 0; j < capacity; j++) printf("%d ", frames[j] == -1 ? -1 : frames[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int n, capacity;
    printf("Enter number of pages and frames: ");
    scanf("%d %d", &n, &capacity);

    int pages[n];
    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);

    FCFS_PageReplacement(pages, n, capacity);
    return 0;
}
