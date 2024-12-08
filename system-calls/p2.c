#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
    pid_t child1PID, child2PID;
    child1PID = fork();
    
    if(child1PID == -1){
        perror("Faild to fork");
        exit(1);
    }
    else if(child1PID == 0){
        printf("Child 1 is executing\n");
        execl("/bin/ls", "ls", NULL);
        perror("execl Faild\n");
        exit(1);
    }else{
        printf("Parrent Waiting\n");
        wait(NULL);
        printf("Parrent:Child 1 is completed\n");
        
        //second fork
        child2PID = fork();
        if(child2PID == -1){
            perror("Fork 2 Failed\n");
            exit(1);
        }else if(child2PID == 0){
            printf("Child 2\n");
            sleep(5);
            printf("child 2 orphan\n");
            exit(0);
        }else{
            printf("Parrent: Exit\n");
            exit(0);
        }
    }
}
