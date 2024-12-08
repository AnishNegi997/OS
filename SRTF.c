#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    int at[n], bt[n], wt[n], tat[n], p[n];
    int remaining_bt[n], completed = 0;
    int totalWT = 0, totalTAT = 0;
    printf("Burst Time:");
    for(int i =0;i<n;i++){
        p[i] = i+1;
        scanf("%d", &bt[i]);
    }
    printf("Arrival Time:");
    for(int i = 0;i<n;i++){
        scanf("%d", &at[i]);
    }

    for(int i = 0;i<n;i++){
        remaining_bt[i] = bt[i];
    }
    int currentTime = 0;

    printf("Gantt's Chart:");
    while(completed!= n){
        int mini = -1, minbt = 9999;
        for(int i = 0;i<n;i++){
            if(at[i]<= currentTime && remaining_bt[i]>0 && remaining_bt[i] < minbt){
                minbt = remaining_bt[i];
                mini = i;
            }
        }
        if(mini == -1){
            currentTime++;
            continue;
        }
        currentTime++;
        printf(" P%d |", p[mini]);
        remaining_bt[mini]--;
        if(remaining_bt[mini] == 0){
            completed++;
            tat[mini] = currentTime - at[mini];
            wt[mini] = tat[mini] - bt[mini];
            totalTAT+= tat[mini];
            totalWT += wt[mini];
        }
    }

    printf("\nAverage Turnaround Time: %f", (float)totalTAT/n);
    printf("\nAverage waiting time: %f", (float)totalWT/n);
}