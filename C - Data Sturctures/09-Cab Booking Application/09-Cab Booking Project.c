#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int cab_id;
    int is_booked; 
} Cab;

struct Customer {
    char name[50];
    int phone;
    int cab_id;
    struct Customer* next;
};

struct Customer* head = NULL;

void initializeCabs(Cab cabs[], int n) {
    for (int i = 0; i < n; i++) {
        cabs[i].cab_id = i + 1;
        cabs[i].is_booked = 0; 
    }
}

void displayAvailableCabs(Cab cabs[], int n) {
    printf("Available Cabs:\n");
    for (int i = 0; i < n; i++) {
        if (!cabs[i].is_booked) {
            printf("Cab ID: %d\n", cabs[i].cab_id);
        }
    }
}

void bookCab(Cab cabs[], int n) {
    int cab_id;
    char name[50];
    int phone;
    
    displayAvailableCabs(cabs, n);
    
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your phone number: ");
    scanf("%d", &phone);
    
    printf("Enter the Cab ID to book: ");
    scanf("%d", &cab_id);
    
    if (cab_id > 0 && cab_id <= n && cabs[cab_id - 1].is_booked == 0) {
        cabs[cab_id - 1].is_booked = 1;
        
        struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
        strcpy(new_customer->name, name);
        new_customer->phone = phone;
        new_customer->cab_id = cab_id;
        new_customer->next = head;
        head = new_customer;
        
        printf("Cab %d has been successfully booked by %s!\n", cab_id, name);
    } else {
        printf("Sorry, this cab is already booked or invalid cab ID!\n");
    }
}

void displayBookedCabs() {
    struct Customer* temp = head;
    
    if (temp == NULL) {
        printf("No cabs are booked currently.\n");
    } else {
        printf("Booked Cabs:\n");
        while (temp != NULL) {
            printf("Cab ID: %d, Booked by: %s, Phone: %d\n", temp->cab_id, temp->name, temp->phone);
            temp = temp->next;
        }
    }
}

void cancelBooking(Cab cabs[], int n) {
    int cab_id;
    printf("Enter the Cab ID to cancel booking: ");
    scanf("%d", &cab_id);
    
    if (cab_id > 0 && cab_id <= n && cabs[cab_id - 1].is_booked == 1) {
        cabs[cab_id - 1].is_booked = 0;
        
        struct Customer *temp = head, *prev = NULL;
        
        while (temp != NULL && temp->cab_id != cab_id) {
            prev = temp;
            temp = temp->next;
        }
        
        if (temp != NULL) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Booking for Cab ID %d has been canceled.\n", cab_id);
        }
    } else {
        printf("Invalid cab ID or cab is not booked.\n");
    }
}

int main() {
    int n = 5; 
    Cab cabs[n];
    int choice;
    
    initializeCabs(cabs, n);
    
    while (1) {
        printf("\n--- Cab Booking System ---\n");
        printf("1. Book a Cab\n");
        printf("2. Display Booked Cabs\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                bookCab(cabs, n);
                break;
            case 2:
                displayBookedCabs();
                break;
            case 3:
                cancelBooking(cabs, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
