#include <stdio.h>
#include <stdlib.h> // For abs()

#define size 200

int c_scan(int arr[], int n) {
    int ans = 0; // Initialize ans to 0
    int pos = 0, head = arr[0];

    // Sorting the array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Find the first request greater than or equal to head
    while (arr[pos] < head) pos++;

    // Process requests moving towards the end of the disk
    for (int i = pos; i < n; i++) {
        ans += abs(arr[i] - head);
        head = arr[i];
    }

    // Move head to the end of the disk, then to the beginning
    ans += (size - 1 - head);
    head = 0;

    // Process requests from the beginning up to the starting point
    for (int i = 0; i < pos; i++) {
        ans += abs(arr[i] - head);
        head = arr[i];
    }

    return ans;
}

int main() {
    int n = 9;
    int arr[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};

    int ans = c_scan(arr, n);
    printf("Total Seek Time: %d\n", ans);
    return 0;
}
