#include<stdio.h>
#include<string.h>
void bestfit(int blockSize[],int processSize[],int nblocks,int nprocess){
    int allocation[nprocess];
    for(int i=0;i<nprocess;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<nprocess;i++){
        int minindex=-1;
        for(int j=0;j<nblocks;j++){
            if(processSize[i]<=blockSize[j]){
                if(minindex==-1||blockSize[minindex]>blockSize[j]){
                minindex=j;
            }
            }
        }
        allocation[i]=minindex;
        blockSize[minindex]=blockSize[minindex]-processSize[i];
    }
     for(int i=0;i<nprocess;i++){
        if(allocation[i]==-1){
            printf("process%d--not allocated\n",i+1);
        }
        else{
            printf("process%d--%d\n",i+1,allocation[i]+1);
        }
       
    }
}
int main(){
        int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int nblocks=sizeof(blockSize)/sizeof(blockSize[0]);
    int nprocess=sizeof(processSize)/sizeof(processSize[0]);
    bestfit(blockSize,processSize,nblocks,nprocess);
    return 0;
}