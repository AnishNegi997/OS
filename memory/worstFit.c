#include <stdio.h>

int main() {
    int num_blocks, num_processes;

    // Input: Number of free blocks and their sizes
    printf("Enter number of free blocks available: ");
    scanf("%d", &num_blocks);
    int block_sizes[num_blocks];
    printf("Enter the block sizes: ");
    for (int i = 0; i < num_blocks; i++) {
        scanf("%d", &block_sizes[i]);
    }

    // Input: Number of processes and their sizes
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    int process_sizes[num_processes];
    printf("Enter the process sizes: ");
    for (int i = 0; i < num_processes; i++) {
        scanf("%d", &process_sizes[i]);
    }

    // Array to keep track of allocated blocks
    int allocation[num_processes];
    for (int i = 0; i < num_processes; i++) {
        allocation[i] = -1; // Initialize as not allocated
    }

    // Worst Fit Allocation
    for (int i = 0; i < num_processes; i++) {
        int worst_index = -1;

        // Find the largest block that can fit the process
        for (int j = 0; j < num_blocks; j++) {
            if (block_sizes[j] >= process_sizes[i]) {
                if (worst_index == -1 || block_sizes[j] > block_sizes[worst_index]) {
                    worst_index = j;
                }
            }
        }

        // If a suitable block is found, allocate it
        if (worst_index != -1) {
            allocation[i] = worst_index + 1; // Allocate block (index + 1 for 1-based index)
            block_sizes[worst_index] -= process_sizes[i]; // Reduce available block size
        }
    }

    // Output: Allocation results
    printf("\nAllocation Results:\n");
    for (int i = 0; i < num_processes; i++) {
        if (allocation[i] != -1) {
            printf("%d - %d\n", process_sizes[i], allocation[i]);
        } else {
            printf("%d - Not Allocated\n", process_sizes[i]);
        }
    }

    return 0;
}
