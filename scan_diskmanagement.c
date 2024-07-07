#include<stdio.h>
#include<stdlib.h>
int s;
int n;
int totalsleektime=0;
void scan(int req[]){
    int direction=1;
    int trigger=0;
    for(int i=s;(i<=199&&i>0);i+=direction){
        
        for(int j=0;j<n;j++){
            if(i==req[j]){
                trigger++;
                int currentseektime=abs(req[j]-s);
                printf("|%d-%d|+",i,s);
                s=i;
                totalsleektime=totalsleektime+currentseektime;
                req[j]=-1;//to show satisifed
                break;
            }
            if(i==199){
                int currentseektime=abs(i-s);
                printf("|%d-%d|+",i,s);
                s=i;
                totalsleektime=totalsleektime+currentseektime;
                direction=-1;
                
                break;
            }
        }
        if(trigger==n){
            break;
        }
    }
}
int main(){
    
    printf("enter the number of requests\n");
    scanf("%d",&n);
   /* printf("enter the requests should be between 0-199\n");
    int req[n];
    for(int i=0;i<n;i++){
        printf("enter req\n");
        scanf("%d",&req[i]);
    }
    */
    int req[] = {98, 183, 37, 122, 14, 124, 65, 67};
    printf("enter the starting pointer");
    scanf("%d",&s);
    //sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(req[j+1]<req[j]){
                int temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    scan(req);
    printf(" total seektime= %d",totalsleektime);
}