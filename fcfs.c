#include<stdio.h>



int main(){
    int n;
    printf("Enter number of processes:");
    scanf("%d", &n);
    int p[n], at[n], bt[n], tat[n], wt[n];
    int totalTAT = 0, totalWT = 0;
    printf("Burst Time:");
    for(int i =0;i<n;i++){
        p[i] = i+1;
        scanf("%d", &bt[i]);
    }
    printf("Arrival Time:");
    for(int i =0;i<n;i++){
        scanf("%d", &at[i]);
    }
    //bubble sorting the proceses accroding to at
    for(int i = 0;i<n-1;i++){
        for(int j =0;i<n-i-1;i++){
            if(at[j] > at[j+1]){
                int temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    printf("Gantt's Chart: ");
    for(int i = 0;i<n;i++){
        printf(" P%d |", p[i]);
    }

    int currentTime = 0;
    for(int i = 0;i<n;i++){
        if(currentTime < at[i]){
            currentTime = at[i];
        }
        wt[i] = currentTime - at[i];
        currentTime+=bt[i];
        tat[i] = wt[i] + bt[i];
        totalTAT+=tat[i];
        totalWT += wt[i];
    }
    
    printf("Average Turnaround Time:%f\n", (float)totalTAT/n);
    printf("Average Waiting Time:%f", (float)totalWT/n);
}