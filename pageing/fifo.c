#include <stdio.h>

int main() {
    int frames, num_requests, page_faults = 0, hits = 0;
    float hit_ratio, hit_percentage;
    
    // Input: Number of frames
    printf("Enter number of frames available: ");
    scanf("%d", &frames);
    
    // Input: Number of requests
    printf("Enter number of page requests: ");
    scanf("%d", &num_requests);
    
    // Input: Pages
    int pages[num_requests];
    printf("Enter the pages: ");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &pages[i]);
    }
    
    // FIFO Implementation
    int memory[frames];  // Array to hold the pages in memory
    int index = 0;       // FIFO index for replacement
    for (int i = 0; i < frames; i++) {
        memory[i] = -1;  // Initialize memory frames to -1 (empty)
    }
    
    for (int i = 0; i < num_requests; i++) {
        int found = 0;
        
        // Check if the page is already in memory
        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = 1;
                hits++; // Page hit
                break;
            }
        }
        
        // If page is not found, replace using FIFO
        if (!found) {
            memory[index] = pages[i];
            index = (index + 1) % frames; // Increment index in a circular manner
            page_faults++;
        }
        
        // Display current memory state
        printf("Memory state after accessing page %d: ", pages[i]);
        for (int j = 0; j < frames; j++) {
            if (memory[j] != -1) 
                printf("%d ", memory[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    
    // Calculate hit ratio and percentage
    hit_ratio = (float)hits / num_requests;
    hit_percentage = hit_ratio * 100.0;
    
    // Output: Total number of page faults, hit ratio, and hit percentage
    printf("\nTotal number of page faults: %d\n", page_faults);
    printf("Total number of hits: %d\n", hits);
    printf("Hit ratio: %.2f\n", hit_ratio);
    printf("Hit percentage: %.2f%%\n", hit_percentage);
    
    return 0;
}
