#include <stdio.h>

#define SIZE 10

// Function to display the array elements
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to update an element at a given index
void updateElement(int arr[], int index, int newValue) {
    if (index >= 0 && index < SIZE) {
        arr[index] = newValue;
        printf("Updated element at index %d to %d.\n", index, newValue);
    } else {
        printf("Index out of bounds!\n");
    }
}

// Function to search for an element and return its index
int searchElement(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;  // Return the index if the element is found
        }
    }
    return -1;  // Return -1 if the element is not found
}

int main() {
    int arr[SIZE];
    
    // Taking user input to populate the array
    printf("Enter %d elements for the array:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int choice;
    while (1) {  
        printf("Enter your choice: ");
        printf("1. Update an element\t");
        printf("2. Search for an element\t");
        printf("3. display array elements\t");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Update operation
                int index, newValue;
                printf("Enter the index you want to update (0-%d): ", SIZE - 1);
                scanf("%d", &index);
                printf("Enter the new value for index %d: ", index);
                scanf("%d", &newValue);
                updateElement(arr, index, newValue);
                break;
            }
            case 2: {
                // Search operation
                int searchValue;
                printf("Enter a value to search in the array: ");
                scanf("%d", &searchValue);
                int foundIndex = searchElement(arr, SIZE, searchValue);
                if (foundIndex != -1) {
                    printf("Element %d found at index %d.\n", searchValue, foundIndex);
                } else {
                    printf("Element %d not found in the array.\n", searchValue);
                }
                break;
            }
            case 3:{
                //displaying the array elements
                displayArray(arr, SIZE);
                break;
            }
            case 4:
                printf("Exiting program.\n");
                return 0;  // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
