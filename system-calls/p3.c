#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<fcntl.h>

int main(){
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if(dir == NULL){
        perror("Unable to open Directory");
        return 1;
    }while((entry = readdir(dir))!=NULL){
        printf("%s\n", entry->d_name);
    }closedir(dir);
}