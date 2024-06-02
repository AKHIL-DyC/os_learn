#include<stdio.h>
#include<string.h>
int findmax(int blockSize[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(blockSize[max]<=blockSize[i]){
            max=i;
        }
    }
return max;
}
void worsfit(int blockSize[],int processSize[],int n){
    int allocation[n];
    memset(allocation,-1,sizeof(allocation));
    for(int i=0;i<n;i++){
        int max=findmax(blockSize,n);
        if(blockSize[max]>processSize[i]){
            blockSize[max]=blockSize[max]-processSize[i];
            allocation[i]=max;
        }
    }
     for(int i=0;i<n;i++){
            printf("process %d process size %d",i+1,processSize[i]);
            if(allocation[i]==-1){
                printf("not allocated\n");
            }
            else{
                printf("allocated on %d\n",allocation[i]);
            }
        }
}
int main(){
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int n=5;
    worsfit(blockSize,processSize,n);
    return 0;
}
