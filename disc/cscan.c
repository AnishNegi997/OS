#include <stdio.h>
#include <stdlib.h> // For abs()

int c_scan(int arr[],int n){
    int ans=0,pos=0,head=arr[0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    while(arr[pos] < head) pos++;
    for(int i=pos;i<n;i++) ans+=abs(arr[i]-head), head=arr[i];
    ans+=(size-1-head)+(size-1),head=0;
    for(int i=0;i<pos;i++) ans+=abs(arr[i]-head),head=arr[i];
    return ans;
}
int main(){
    int n=9;
    int arr[]={55,58,60,70,18,90,150,160,184};
    int ans=fcfs(arr,n);
    printf("%d",ans);
}