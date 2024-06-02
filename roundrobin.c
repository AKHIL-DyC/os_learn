#include<stdio.h>
struct Process{
    int id;
    int bt;
    int wt;
    int ct;
    int tat;
    int rbt;
}p[20];
void main(){
    int n,tq;
    int i=0;//process number
    int rn=0;//completed process
    int totalt=0;
    printf("enter the number of process");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter process id and burst time of process %d",i+1);
        scanf("%d %d",&p[i].id,&p[i].bt);
        p[i].rbt=p[i].bt;
    }
    printf("enter the time quantum");
    scanf("%d",&tq);
    while(1){
        //if bt<tq
        if(p[i].rbt>0){
            if(p[i].rbt>tq){
                p[i].rbt=p[i].rbt-tq;
                totalt=totalt+tq;
            }
            else{
                totalt=totalt+p[i].rbt;
                p[i].rbt=0;
                p[i].ct=totalt;
                p[i].wt=p[i].ct-p[i].bt;
                rn++;
                if(rn==n){
                    break;
                }
            }

        }
        if(i==n-1)
        {i=0;}
        else{
            i=i+1;
        }

    }

    for(int i=0;i<n;i++){
        printf("%d \t%d\t %d\t%d\n",i,p[i].bt,p[i].ct,p[i].wt);
    }
}