#include <stdio.h>

int main() {
    int array[100], high, low, mid, n, key;

    printf("Enter the number of elements in the array: ");
    scanf("%i", &n);

    printf("Enter the elements in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %i: ", i + 1);
        scanf("%i", &array[i]);
    }

    printf("What number do you want to find? ");
    scanf("%i", &key);   

    high=n-1;
    low=0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (key == array[mid]) {
            printf("Found at position %i.\n", mid + 1);
            break; 
        } else if (key < array[mid]) {
            high = mid - 1;  
        } else {
            low = mid + 1;  
        }
    }
    if (low > high) {
        printf("Number not found in the array.\n");
    }

    return 0;
}
