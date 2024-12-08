#include<stdio.h>

int main(){
    int n;
    printf("Enter number of Processes:");
    scanf("%d",&n);
    int at[n], bt[n], priority[n],remaining_bt[n], completed = 0;
    int tat[n], wt[n], totalTAT = 0, totalWT = 0, currentTime = 0; 
    int p[n];
    printf("Burst Time:");
    for(int i =0;i<n;i++){
        p[i] = i+1;
        scanf("%d", &bt[i]);
    }
    printf("Arrival Time:");
    for(int i =0;i<n;i++){
        scanf("%d", &at[i]);
    }
    printf("Priority:");
    for(int i =0;i<n;i++){
        scanf("%d", &priority[i]);
    }
    for(int i =0;i<n;i++){
        remaining_bt[i] = bt[i];
    }
    printf("Gantt's Chart:");
    while(completed!=n){
        int mini = -1, highest_priority = 99999;
        for(int i = 0;i<n;i++){
            if(at[i]<= currentTime && remaining_bt[i] && highest_priority>priority[i]){
                highest_priority = priority[i];
                mini = i;
            }
        }
        if(mini == -1){
            currentTime++;
            continue;
        }
        currentTime++;
        remaining_bt[mini]--;
        printf(" P%d |", p[mini]);
        if(remaining_bt[mini] == 0){
            completed++;
            tat[mini] = currentTime - at[mini];
            wt[mini] = tat[mini] - bt[mini];
            totalTAT+=tat[mini];
            totalWT += wt[mini];
        }
    }
    printf("\nAverage Turnarround Time: %f", (float)totalTAT/n);
    printf("\nAverage Waiting Time: %f", (float)totalWT/n);
}