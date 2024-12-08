#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    int p[n], at[n], bt[n], tat[n], wt[n], tq;
    printf("Enter the Time Quanta:");
    scanf("%d", &tq);
    printf("Burst Time:");
    for(int i =0;i<n;i++){
        scanf("%d", &bt[i]);
    }int remaining_bt[n];
    printf("Arrival Time:");
    for(int i =0;i<n;i++){
        p[i] = i+1;
        scanf("%d", &at[i]);
        remaining_bt[i] = bt[i];
    }
    int completed = 0, currentTime = 0;
    int totalWT = 0, totalTAT = 0;
    printf("\nGantt's Chart:");
    while(completed!=n){
        int done = 0;
        for(int i =0;i<n;i++){
            if(at[i]<=currentTime && remaining_bt[i]>0){
                if(tq < remaining_bt[i]){
                    printf(" P%d |", p[i]);
                    remaining_bt[i] -= tq;
                    currentTime+=tq;
                }else{
                    printf(" P%d |", p[i]);
                    currentTime+=remaining_bt[i];
                    remaining_bt[i] = 0;
                    tat[i] = currentTime - at[i];
                    wt[i] = tat[i] - bt[i];
                    totalTAT += tat[i];
                    totalWT+= wt[i];
                    completed++;
                }
                done = 1;
            }
        }
        if(done == 0){
            currentTime++;
        }
    }

    printf("\nAverage Turnarround Time:%f", (float)totalTAT/n);
    printf("\nAverage Waiting Time: %f", (float)totalWT/n);
}