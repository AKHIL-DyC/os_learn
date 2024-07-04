#include <stdio.h>

struct process {
    int wt;
    int bt;
    int at;
    int ct;
    int tat;
    int completed;
} p[5];

int main() {
    int currentTime = 0;
    int totalTime = 0;
    int n = 5;

    // Initialize processes
    p[0].at = 2, p[1].at = 5, p[2].at = 0, p[3].at = 0, p[4].at = 7;
    p[0].bt = 2, p[1].bt = 6, p[2].bt = 4, p[3].bt = 7, p[4].bt = 4;
    
    for (int i = 0; i < n; i++) {
        totalTime += p[i].bt;
        p[i].completed = 0;
    }

    while (currentTime < totalTime) {
        int index = -1;  // Initialize to -1 to indicate no process found

        for (int i = 0; i < n; i++) {
            // Check if the process has arrived and is not completed
            if (p[i].at <= currentTime && !p[i].completed) {
                // If no process is selected yet, or if the current process has a smaller arrival time
                if (index == -1 || p[i].at < p[index].at) {
                    index = i;
                }
            }
        }

        // If no process is available, increment the current time
        if (index == -1) {
            currentTime++;
            continue;
        }

        // Process with the smallest arrival time found
        p[index].completed = 1;
        currentTime += p[index].bt;
        p[index].ct = currentTime;
    }

    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    printf("Process AT  BT  CT  TAT WT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
