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
    int n = 5;
    int currentTime = 0;
    int totalTime = 0;

    // Initialize processes
    p[0].at = 1, p[1].at = 3, p[2].at = 6, p[3].at = 7, p[4].at = 9;
    p[0].bt = 7, p[1].bt = 3, p[2].bt = 2, p[3].bt = 10, p[4].bt = 8;
    
    for (int i = 0; i < n; i++) {
        p[i].completed = 0;
        totalTime += p[i].bt;
    }

    while (currentTime < totalTime) {
        int minBtIndex = -1;
//complete akkatha minimum bt ollath select akka
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && !p[i].completed) {
                if (minBtIndex == -1 || p[i].bt < p[minBtIndex].bt) {
                    minBtIndex = i;
                }
            }
        }

        if (minBtIndex != -1) {
            p[minBtIndex].completed = 1;
            currentTime += p[minBtIndex].bt;
            p[minBtIndex].ct = currentTime;
        } else {
            currentTime++;
        }
    }
for(int i =0;i<n;i++){
    p[i].tat=p[i].ct-p[i].at;
    p[i].wt=p[i].tat-p[i].bt;
}
    for (int i = 0; i < n; i++) {
        printf("Process %d: BT = %d, AT = %d, CT = %d,TAT = %d,WT = %d\n", i+1, p[i].bt, p[i].at, p[i].ct,p[i].tat,p[i].wt);
    }

    return 0;
}
