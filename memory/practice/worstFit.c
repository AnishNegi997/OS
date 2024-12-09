#include<stdio.h>

int main(){
    int blocks, processes;
    printf("Enter the number of blocks:");
    scanf("%d", &blocks);
    int blockArray[blocks];
    printf("Enter the blocks sizes:");
    for(int i =0;i<blocks;i++){
        scanf("%d", &blockArray[i]);
    }
    printf("Enter the numberof processes:");
    scanf("%d", &processes);
    int processArray[processes], allocated[processes];
    printf("Enter the process sizes:");
    for(int i =0;i<processes;i++){
        allocated[i] = -1;
        scanf("%d", &processArray[i]);
    }
    //working
    for(int i =0;i<processes;i++){
        int maxBlock = -1, maxIdx = -1;
        for(int j =0;j<blocks;j++){
            if(blockArray[j] >= processArray[i]){
                if(maxBlock<blockArray[j]){
                    maxBlock = blockArray[j];
                    maxIdx = j;
                }
            }
        }
        if(maxIdx!=-1){
            allocated[i] = maxIdx+1;
            // blockArray[maxIdx] -= processArray[i]; 
            blockArray[maxIdx] = 0;
        }
    }
    printf("Output:\n");
    for(int i =0;i<processes;i++){
        if(allocated[i] != -1){
            printf("%d - %d\n", processArray[i], allocated[i]);
        }
        else{
            printf("%d - No free block allocated\n", processArray[i]);
        }
    }
}