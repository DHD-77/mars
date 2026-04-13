#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decode_rover_message(char* message) {
    int length = strlen(message);
    char decoded[length + 1];

    for (int i = 0; i < length; i++) {
        // 1. Convert to uppercase
        char c = toupper(message[i]);

        // 2. Calculate shift (index + 1)
        int shift = i + 1;

        // 3. Reverse the shift
        // We subtract 'A' to get 0-25 range, subtract shift, 
        // add 26 to handle negative results, then mod 26.
        char original = ((c - 'A' - shift) % 26 + 26) % 26 + 'A';

        decoded[i] = original;
    }

    decoded[length] = '\0'; // Null-terminate string
    printf("Decoded Message: %s\n", decoded);
}

int main() {
    char input[] = "NCUW"; // Example input
    
    printf("Original Input: %s\n", input);
    decode_rover_message(input);

    return 0;
}