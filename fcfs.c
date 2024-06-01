#include<stdio.h>
int wat[5];
int tt[5];
void wt(int n,int bt[],int at[]){
    wat[0]=0;
    for(int i=1;i<n;i++){
        wat[i]=bt[i-1]+wat[i-1]+at[i-1]-at[i];
    }
}
void tat(int n,int bt[],int wt[]){
    for(int i=0;i<n;i++){
        tt[i]=bt[i]+wt[i];
    }
}
int main(){
    int process[]={1,2,3,4,5};
    int bt[]={8,1,3,2,6};
    int at[]={0,1,2,3,4};
    int n=5;
    wt(n,bt,at);
    tat(n,bt,wat);
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",at[i],bt[i],wat[i],tt[i]);
    }
    return 0;
}