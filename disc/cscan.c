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
    // int start = requests[0];
    int start = 50; //lets assume
    head = requests[0];
    int biggest = -1, smallest = -1;
    for(int i = 0;i<num_requests;i++){
        if(requests[i]>biggest){
            biggest = requests[i];
        }
        if(requests[i] < start){
            if(smallest == -1 || requests[i] > smallest){
                smallest = requests[i];
            }
        }
    }
    biggest = 199; //assuming

    printf("Biggest = %d, smallest = %d, start = %d\n", biggest, smallest, start);
    printf("(%d - %d) + (%d - 0) + (%d - 0)\n", biggest, start, biggest, smallest);
    int result = abs(biggest - start) + biggest + smallest; //if user want to move up first
    // int result = abs(requests[0] - smallest) + abs(smallest - biggest); //if user wants to move downwards first
    printf("Total seek Movement: %d", result);
}
