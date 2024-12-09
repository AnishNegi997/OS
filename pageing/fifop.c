#include<stdio.h>

int main(){
    int frames, processes;
    printf("Enter number of frames:");
    scanf("%d", &frames);
    printf("Enter number of processes:");
    scanf("%d", &processes);
    int processArray[processes], frameArray[frames];
    printf("Enter the processes:");
    for(int i=0;i<processes;i++){
        scanf("%d", &processArray[i]);
    }
    for(int i =0;i<frames;i++){
        frameArray[i] = -1;
    }
    int hit = 0, pageFault = 0, idx = 0;
    //working
    for(int i = 0;i<processes;i++){
        int didHit = 0;
        for(int j =0;j<frames;j++){
            if(frameArray[j] == processArray[i]){
                hit++;
                didHit = 1;
                break;
            }
        }
        if(!didHit){
            pageFault++;
            frameArray[idx] = processArray[i];
            idx = (idx + 1)%frames;
        }
        printf("Frames at inserting page %d:", processArray[i]);
        for(int j =0;j<frames;j++){
            if(frameArray[j] == -1){
                printf("- ");
            }else{
                printf("%d ", frameArray[j]);
            }
        }
        printf("\n");
    }
    printf("\nNumber of page Faults: %d", pageFault);
}