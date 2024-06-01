#include<stdio.h>
int tt[5];
int wt[5];
void tat(int n,int bt[]){
    wt[0]=0;
    tt[0]=wt[0]+bt[0];
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tt[i]=wt[i]+bt[i];
    }
    
}
int main(){
    int bt[]={8,1,3,2,6};
    int n=5;
    for(int i=0;i<n-1;i++){
        for(int j=0; j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                int temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
            }
        }
    }
    tat(n,bt);
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\n",bt[i],wt[i],tt[i]);
    }
    return 0;
}