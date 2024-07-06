//this program fill the first three frames instantly ,star this repo nigga
#include<stdio.h>
#define fsize 3
struct frame{
    int value;
    int order;
}f[fsize];
int hit=0;
int miss=3;
int order=2;
int pageinframe(int p){
    int flag=0;
    for(int i=0;i<fsize;i++){
        if(p==f[i].value){
            flag=1;
            return i;
        }
    }
    if(flag==0){
        return 0;
    }
};
void printframe(){
    for(int i=0;i<fsize;i++){
        printf("%d",f[i].value);
    }
    printf("\n");
}
void lru(int pagesequence[],int n){
    for(int i=3;i<n;i++){
        //find min order that will be the oldest
        int min=0;
        int pageexistinframe=pageinframe(pagesequence[i]);
        if(pageexistinframe==0){
            for(int j=0;j<fsize;j++){
            if(f[min].order>f[j].order){
                min=j;
            }
        } 
        f[min].value=pagesequence[i];
        f[min].order=order+1;
        miss++;
        printf("page %d replaced with frame %d\n",i,min);
        }
        else{
            int position=pageinframe(pagesequence[i]);
            f[position].order=order+1;
            hit++;
            printf("page already exist in frame\n");
        }
        
printframe();
}
}
int main(){
    int pagesequence[]={1 ,3, 0, 3 ,5 ,6 ,3};
    for(int i=0;i<fsize;i++){
        f[i].value=pagesequence[i];
        f[i].order=i;
    }
    lru(pagesequence,7);
    return 0;
}