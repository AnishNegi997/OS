#include<stdio.h>

int main(){
    int frames, processes;
    printf("Enter number of frames:");
    scanf("%d", &frames);
    printf("Enter number of processes:");
    scanf("%d", &processes);
    int processArray[processes], frameArray[frames], age[frames];
    printf("Enter the processes:");
    for(int i=0;i<processes;i++){
        scanf("%d", &processArray[i]);
    }
    for(int i =0;i<frames;i++){
        frameArray[i] = -1;
        age[i] = 0;
    }
    int hit = 0, pageFault = 0, idx = 0, counter = 0;
    //working
    for(int i = 0;i<processes;i++){
        int didHit = 0;
        for(int j =0;j<frames;j++){
            if(frameArray[j] == processArray[i]){
                didHit=1;
                hit++;
                age[j] = ++counter;
                break;
            }
        }
        if(!didHit){
            int pos = -1;
            for(int j = 0;j<frames;j++){
                if(frameArray[j] == -1){
                    pos=j;
                    break;
                }
            }
            if(pos == -1){
                int minAge = age[0], pos = 0;
                for(int j = 1;j<frames;j++){
                    if(minAge > age[j]){
                        minAge = age[j];
                        pos = j;
                    }
                }
            }
            frameArray[pos] = processArray[i];
            age[pos] = ++counter; 
            pageFault++;
        }
        printf("At page %d:", processArray[i]);
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