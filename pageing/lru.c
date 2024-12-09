#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

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

    int memory[frames];  // Array to hold the pages in memory
    int time[frames];    // Array to store the last used time of pages
    int counter = 0;     // Counter to track time

    for (int i = 0; i < frames; i++) {
        memory[i] = -1;  // Initialize memory frames to -1 (empty)
        time[i] = 0;     // Initialize times to 0
    }

    for (int i = 0; i < num_requests; i++) {
        int found = 0;

        // Check if the page is already in memory
        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = 1;
                hits++;
                time[j] = ++counter; // Update the last used time
                break;
            }
        }

        // If page is not found, replace the least recently used page
        if (!found) {
            int pos = -1;
            for (int j = 0; j < frames; j++) {
                if (memory[j] == -1) {
                    pos = j;
                    break;
                }
            }
            if (pos == -1) {
                pos = findLRU(time, frames);
            }
            memory[pos] = pages[i];
            time[pos] = ++counter; // Update the last used time
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
