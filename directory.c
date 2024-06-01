#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
struct dirent *dptr;
int main(int argc,char *argcv[]){
    char buff[100];
    printf("\n\n ENTER DIRECTORY NAME\n");
    scanf("%s", buff);
    DIR *dirp;
    if((dirp=opendir(buff))==NULL){
        printf("directory doesnt exist");
        exit(1);
    }
    while (dptr=readdir(dirp))
    {
        printf("%s\n",dptr->d_name);
    }
    closedir(dirp);
    return 0;
}