#include<stdio.h>

int main(){
    int n, m;
    printf("Enter number of processes:");
    scanf("%d", &n);
    printf("Enter number of resources:");
    scanf("%d", &m);
    int max[n][m], allocated[n][m], need[n][m];
    printf("Enter max matrix:\n");
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            scanf("%d", &max[i][j]);
        }
    }printf("Enter Allocated matrix:\n");
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            scanf("%d", &allocated[i][j]);
        }
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
    printf("Need matrix:\n");
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    int maxResources[m], avilable[m];
    printf("Enter max Resources:");
    for(int i = 0;i<m;i++){
        avilable[i] = 0;
        scanf("%d", &maxResources[i]);
    }
    for(int j =0;j<m;j++){
        for(int i = 0;i<n;i++){
            avilable[j] += allocated[i][j];
        }
    }
    for(int i = 0;i<m;i++){
        avilable[i] = maxResources[i] - avilable[i];
    }

    int finished[n], ans[n], idx = 0;
    for(int i=0;i<n;i++){
        finished[i] = 0;
    }

    for(int k = 0;k<n;k++){
        for(int i =0;i<n;i++){
            if(finished[i] == 0){
                int flag = 0;
                for(int j = 0;j<m;j++){
                    if(need[i][j] > avilable[j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    finished[i] = 1;
                    ans[idx++] = i;
                    for(int j =0;j<m;j++){
                        avilable[j] += allocated[i][j];
                    }
                }
            }
        }
    }
    int flag = 0;
    for(int i =0;i<n;i++){
        if(finished[i] == 0){
            printf("Deadlock");
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        for(int i =0;i<n;i++){
            printf("\nSafe Sequence:");
            printf("P%d ", ans[i]);
        }
    }
}