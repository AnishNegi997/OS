#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    int p[n], at[n], bt[n], tat[n], wt[n];
    int totalWT = 0, totalTAT = 0;
    int remaining_bt[n], completed = 0;
    printf("Burst Time:");
    for(int i =0;i<n;i++){
        p[i] = i+1;
        scanf("%d", &bt[i]);
    }
    printf("Arrival Time:");
    for( int i =0;i<n;i++){
        scanf("%d", &at[i]);
    }


    int current = 0;
    for(int i =0;i<n;i++){
        remaining_bt[i] = bt[i];
    }

    printf("Gantt's Chart:");
    while(completed!= n){
        int mini = 0, minbt = 9999;
        for(int i = 0;i<n;i++){
            if(at[i]<=current && remaining_bt[i]>0 && remaining_bt[i]<minbt){
                minbt = remaining_bt[i];
                mini = i;
            }
        }
        if(mini == -1){
            current++;
            continue;
        }
         printf(" P%d |", p[mini]);
        current+=remaining_bt[mini];
        remaining_bt[mini] = 0;
        completed++;
        tat[mini] = current - at[mini];
        wt[mini] = tat[mini] - bt[mini];
        totalTAT += tat[mini];
        totalWT += wt[mini];
    }
    
    printf("\nAverage Turnaround Time:%f\n", (float)totalTAT/n);
    printf("Average Waiting Time:%f", (float)totalWT/n);
}