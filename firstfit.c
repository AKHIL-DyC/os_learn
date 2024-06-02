#include<stdio.h>
#include<string.h>
void firstfit(int blockSize[],int processSize[],int n){
    int allocation[n];
    memset(allocation,-1,sizeof(allocation));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(blockSize[j]>processSize[i]){
                blockSize[j]=blockSize[j]-processSize[i];
                allocation[i]=j;
                break;
            }
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
    int n=5;
     int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    firstfit(blockSize,processSize,n);
    return 0;
}