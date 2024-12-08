#include<stdio.h>

int main(){
    int n, m;
    printf("Enter number of user processes:");
    scanf("%d", &n);
    printf("Enter number of system Processes:");
    scanf("%d", &m);
    int ubt[n], uat[n], up[n], sbt[m], sat[m], sp[m], tat[n+m], wt[n+m];
    printf("Enter user arrival times:");
    for(int i =0;i<n;i++){
        up[i] = i+1;
        scanf("%d", &uat[i]);
    }
    printf("Enter user burst times:");
    for(int i =0;i<n;i++){
        scanf("%d", &ubt[i]);
    }
    printf("Enter system arrival times:");
    for(int i =0;i<m;i++){
        sp[i] = i+1;
        scanf("%d", &sat[i]);
    }
    printf("Enter system burst times:");
    for(int i =0;i<m;i++){
        scanf("%d", &sbt[i]);
    }
    int totalTime = 0;
    for(int i =0;i<n;i++){
        totalTime+=ubt[i];
    }
    for(int i =0;i<m;i++){
        totalTime+=sbt[i];
    }
    int currentTime = 0, totalTAT = 0, totalWT = 0;
    while(currentTime!=totalTime){
        int u = -1, s = -1;
        for(int i =0;i<n;i++){
            if(uat[i]<=currentTime && ubt[i] > 0){
                u = i;
                break;
            }
        }
        for(int i =0;i<m;i++){
            if(sat[i]<=currentTime && sbt[i] > 0){
                s = i;
                break;
            }
        }
        if(s != -1 && (u == -1 || sat[s] <= uat[u])){
            printf("\nSYSTEM P%d: %d", sp[s], currentTime);
            currentTime+=sbt[s];
            tat[s + n] = currentTime - sat[s];
            wt[s + n] = tat[s+n] - sbt[s];
            totalTAT += tat[s + n];
            totalWT += wt[s + n];
            sbt[s] = 0;
            continue;
        }
        if(u != -1 && (s == -1 || uat[u] < sat[s])){
            printf("\nUser P%d: %d", up[u], currentTime);
            currentTime+=ubt[u];
            tat[u] = currentTime - uat[u];
            wt[u] = tat[u] - ubt[u];
            totalTAT += tat[u];
            totalWT += wt[u];
            ubt[u] = 0;
            continue;
        }else{
            currentTime++;
            printf("\nIDEL");
        }
    }
    printf("\nAverage TAT:%f", (float)totalTAT/(n+m));
    printf("\nAverage WT: %f", (float)totalWT/(n+m));
}