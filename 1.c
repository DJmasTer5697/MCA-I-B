//Write a Program to perform various operations in the list: insertion, deletion, display. 

#include <stdio.h>g
#define MAX 100  // Maximum size of the list

int main() {
    int list[MAX];
    int n = 0; 
    int choice;

    while(1) {
        printf("\n--- List Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            if(n >= MAX) {
                printf("List is full! Cannot insert more elements.\n");
            } else {
                int element, pos;
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                if(pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    // Shift elements to the right
                    for(int i = n; i > pos; i--) {
                        list[i] = list[i-1];
                    }
                    list[pos] = element;
                    n++;
                    printf("Element inserted.\n");
                }
            }
        } else if(choice == 2) {
            if(n == 0) {
                printf("List is empty! Nothing to delete.\n");
            } else {
                int pos;
                printf("Enter position to delete (0 to %d): ", n-1);
                scanf("%d", &pos);
                if(pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                } else {
                    int removed = list[pos];
                    // Shift elements to the left
                    for(int i = pos; i < n-1; i++) {
                        list[i] = list[i+1];
                    }
                    n--;
                    printf("Deleted element: %d\n", removed);
                }
            }
        } else if(choice == 3) {
            if(n == 0) {
                printf("List is empty.\n");
            } else {
                printf("Current List: ");
                for(int i = 0; i < n; i++) {
                    printf("%d ", list[i]);
                }
                printf("\n");
            }
        } else if(choice == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}