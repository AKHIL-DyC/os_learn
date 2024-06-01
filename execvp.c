#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
    pid_t pid=fork();
    if(pid<0){
        perror("fork failed");
    }
    else if(pid==0){
        printf("in child procees executing ls-l command");
        char * arg[]={"ls","-l",NULL};
        execvp(arg[0],arg);
        perror("execvp failed");
        exit(1);
    }
    else{
        printf("in parent process %d",getpid());
        wait(NULL);

    }

    return 0;
}
