#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    pid_t pid = fork();
    if(pid<0){
        printf("Fork Failed");
    }
    else if(pid == 0){
        printf("This is the child Process Child PID: %d\n", getpid());
        printf("This is child Process Parrent PID: %d\n", getppid());
    }else{
        printf("This is parrent Process Child PID: %d\n", pid);
        printf("Thi is parrent Process Parrent Pid: %d\n", getpid());
    }
}