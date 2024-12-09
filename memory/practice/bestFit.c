#include<stdio.h>

int main(){
    int blocks, processes;
    printf("Enter number of blocks:");
    scanf("%d", &blocks);
    int blockArray[blocks];
    printf("Enter the block sizes:");
    for(int i =0;i<blocks;i++){
        scanf("%d", &blockArray[i]);
    }
    printf("Enter number of processes:");
    scanf("%d", &processes);
    int processArray[processes], result[processes];
    printf("Enter the process sizes:");
    for(int i =0;i<processes;i++){
        result[i] = -1;
        scanf("%d", &processArray[i]);
    }
    //working
    for(int i =0;i<processes;i++){
        int mini = -1, min = 99999;
        for(int j = 0;j<blocks;j++){
            if(blockArray[j]>=processArray[i]){
                if(min > blockArray[j]){
                    min = blockArray[j];
                    mini =j;
                }
            }
        }
        if(mini != -1){
            result[i] = mini + 1;
            blockArray[mini] -=processArray[i];
        }
    }
    printf("Output:\n");
    for(int i =0;i<processes;i++){
        if(result[i] == -1){
            printf("%d - no memory allocated\n", processArray[i]);
        }else{
            printf("%d - %d\n", processArray[i], result[i]);
        }
    }
}