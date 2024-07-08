#include <stdio.h>
#include <stdlib.h>

#define nprocess 6 

int completedprocess = 0;
int currenttime = 0;
int timequanta = 4;

struct process {
    int bt;
    int rbt;
    int at;
    int wt;
    int ct;
    int tat;
    int done;
    int inqueue;
} p[nprocess];

struct queue {
    struct process* data;
    struct queue* next;
};

struct queue* head = NULL;
struct queue* tail = NULL;

struct queue* newnodecreator(struct process* data) {
    struct queue* newnode = (struct queue*)malloc(sizeof(struct queue));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void enqueue(struct process* data) {
    struct queue* newnode = newnodecreator(data);
    if (tail == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

struct process* dequeue() {
    if (head == NULL) {
        return NULL;
    } else {
        struct queue* temp = head;
        struct process* data = temp->data;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        free(temp);
        return data;
    }
}

void roundrobin() {
    while (completedprocess < nprocess) {
        for (int i = 0; i < nprocess; i++) {
            if (!p[i].done && p[i].at <= currenttime && !p[i].inqueue) {
                enqueue(&p[i]);
                p[i].inqueue = 1;
            }
        }

        struct process* currentprocess = dequeue();
        if (currentprocess != NULL) {
            if (currentprocess->rbt <= timequanta) {
                currenttime += currentprocess->rbt;
                currentprocess->ct = currenttime;
                currentprocess->tat = currentprocess->ct - currentprocess->at;
                currentprocess->wt = currentprocess->tat - currentprocess->bt;
                currentprocess->rbt = 0;
                currentprocess->done = 1;
                completedprocess++;
            } else {
                currenttime += timequanta;
                currentprocess->rbt -= timequanta;

                // Check for new arrivals during this period
                for (int i = 0; i < nprocess; i++) {
                    if (!p[i].done && p[i].at <= currenttime && !p[i].inqueue) {
                        enqueue(&p[i]);
                        p[i].inqueue = 1;
                    }
                }
                // Re-enqueue the current process
                enqueue(currentprocess);
            }
        } else {
            // If no process is ready to execute, just increment the time
            currenttime++;
        }
    }
}

int main() {
    p[0].at = 0; p[0].bt = 5;
    p[1].at = 1; p[1].bt = 6;
    p[2].at = 2; p[2].bt = 3;
    p[3].at = 3; p[3].bt = 1;
    p[4].at = 4; p[4].bt = 5;
    p[5].at = 6; p[5].bt = 4;

    for (int i = 0; i < nprocess; i++) {
        p[i].done = 0;
        p[i].inqueue = 0;
        p[i].rbt = p[i].bt;
    }

    // Sort processes by arrival time (optional as we enqueue based on arrival time)
    for (int i = 0; i < nprocess - 1; i++) {
        for (int j = 0; j < nprocess - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    roundrobin();

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for (int i = 0; i < nprocess; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
            i, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
