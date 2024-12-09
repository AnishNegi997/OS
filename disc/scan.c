#include <stdio.h>
#include <stdlib.h> // For abs()

int main() {
    int num_requests, head, total_seek = 0;
    // Input: Number of disk requests
    printf("Enter number of disk requests: ");
    scanf("%d", &num_requests);
    int requests[num_requests];
    // Input: Disk request queue
    printf("Enter the disk requests (first is the start point): ");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }
    head = requests[0];
    int biggest = -1, smallest = 999999;
    for(int i = 0;i<num_requests;i++){
        if(requests[i]>biggest){
            biggest = requests[i];
        }
        if(smallest > requests[i]){
            smallest = requests[i];
        }
    }
    biggest = 199;
    // int start = requests[0];
    int start = 50;//assuming
    printf("Biggest = %d, smallest = %d, start = %d\n", biggest, smallest, requests[0]);
    int result = abs(start - biggest) + abs(biggest - smallest); //if user want to move up first
    // int result = abs(requests[0] - smallest) + abs(smallest - biggest); //if user wants to move downwards first
    printf("Total seek Movement: %d", result);
}
