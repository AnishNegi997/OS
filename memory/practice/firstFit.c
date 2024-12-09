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
        for(int j = 0;j<blocks;j++){
            if(blockArray[j]>=processArray[i]){
                result[i] = j+1;
                blockArray[j] -=processArray[i];
                break;
            }
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