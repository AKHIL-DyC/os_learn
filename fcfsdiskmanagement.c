#include<stdio.h>
#include<stdlib.h>
int findseektime(int n,int requests[]){
    int totalsleektime=0;
    int currentposition=0;
    int sleektime;
    for(int i=0;i<n;i++){
        sleektime=abs(currentposition-requests[i]);
        currentposition=requests[i];
        totalsleektime=totalsleektime+sleektime;
    }
    return totalsleektime;
}
int main(){
    int n;
    printf("enter the number of requests");
    scanf("%d",&n);
    int requests[n];
    printf("enter the requests");
    for(int i=0;i<n;i++){
        scanf("%d",&requests[i]);
    }
    int result=findseektime(n,requests);
    printf("the sleek time is %d",result);
    return 0;
}