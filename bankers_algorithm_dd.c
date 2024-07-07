#include <stdio.h>
#define nprocess 5
#define nresource 3

struct process {
    int max[nresource];
    int need[nresource];
    int allocation[nresource];
    int done;
} p[nprocess];

int cansatisfy(int available[], int pr[]) {
    for (int i = 0; i < nresource; i++) {
        if (available[i] < pr[i]) {
            return 0;
        }
    }
    return 1;
}

void addtoavailable(int available[], int pr[]) {
    for (int i = 0; i < nresource; i++) {
        available[i] = available[i] + pr[i];
    }
}

void printavailable(int available[]) {
    for (int i = 0; i < nresource; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
}

int main() {
    // Value hardcoded for now
    int available[] = {3, 3, 2};

    int maxValues[nprocess][nresource] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int allocationValues[nprocess][nresource] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    for (int i = 0; i < nprocess; i++) {
        for (int j = 0; j < nresource; j++) {
            p[i].max[j] = maxValues[i][j];
            p[i].allocation[j] = allocationValues[i][j];
        }
    }

    for (int i = 0; i < nprocess; i++) {
        p[i].done = 0;
        for (int j = 0; j < nresource; j++) {
            p[i].need[j] = p[i].max[j] - p[i].allocation[j];
        }
    }

    while (1) {
        int flag = 0;
        for (int i = 0; i < nprocess; i++) {
            if (!p[i].done && cansatisfy(available, p[i].need)) {
                flag = 1;
                addtoavailable(available, p[i].allocation);
                p[i].done = 1;
                printf("Process %d can be allocated. Available resources: ", i);
                printavailable(available);
            }
        }
        // If no change in iteration
        if (flag == 0) {
            printf("All processes that can be allocated have been allocated.\n");
            break;
        }
    }
    return 0;
}
