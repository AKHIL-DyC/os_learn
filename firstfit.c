#include<stdio.h>
#include<string.h>
void firstfit(int blockSize[],int processSize[],int nprocess,int nblocks){

    int allocation[nprocess];
   // memset(allocation,-1,nprocess);
   for(int i=0;i<nprocess;i++){
    allocation[i]=-1;
   }
    for(int i=0;i<nprocess;i++){
        for(int j=0;j<nblocks;j++){
            if(processSize[i]<=blockSize[j]){
                blockSize[j]=blockSize[j]-processSize[i];
                allocation[i]=j;
                break;
            }
        }
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
    int nprocess=sizeof(processSize)/sizeof(processSize[0]);
    int nblocks=sizeof(blockSize)/sizeof(blockSize[0]);
    firstfit(blockSize,processSize,nprocess,nblocks);
   
    return 0;
}