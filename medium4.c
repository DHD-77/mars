#include <stdio.h>
#include <stdlib.h>

// Helper to sort a small array for the Median filter
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Muchiko Filter: Moving Average
void muchiko_filter(int data[], int size, int window) {
    printf("Muchiko Output: ");
    for (int i = 0; i <= size - window; i++) {
        int sum = 0;
        for (int j = 0; j < window; j++) {
            sum += data[i + j];
        }
        printf("%d ", sum / window);
    }
    printf("\n");
}

// Sanchiko Filter: Moving Median
void sanchiko_filter(int data[], int size, int window) {
    int temp[window];
    printf("Sanchiko Output: ");
    for (int i = 0; i <= size - window; i++) {
        // Copy window to temp array
        for (int j = 0; j < window; j++) {
            temp[j] = data[i + j];
        }
        sort(temp, window);
        printf("%d ", temp[window / 2]); // Middle element
    }
    printf("\n");
}

int main() {
    int sensor_readings[] = {4, 7, 6, 1, 8}; // Example from your image
    int size = sizeof(sensor_readings) / sizeof(sensor_readings[0]);
    int window_size = 3;

    printf("Processing Sensor Data...\n");
    muchiko_filter(sensor_readings, size, window_size);
    sanchiko_filter(sensor_readings, size, window_size);

    return 0;
}