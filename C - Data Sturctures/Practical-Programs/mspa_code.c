#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the doubly linked list
typedef struct Student {
    int roll_no;
    char name[50];
    struct Student* prev;
    struct Student* next;
} Student;

// Head and Tail pointers
Student* head = NULL;
Student* tail = NULL;

// Function to create a new node
Student* createNode(int roll_no, char* name) {
    Student* newNode = (Student*)malloc(sizeof(Student));
    newNode->roll_no = roll_no;
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add a student at the end of the roll list
void addStudent(int roll_no, char* name) {
    Student* newNode = createNode(roll_no, name);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Student added: Roll No: %d, Name: %s\n", roll_no, name);
}

// Function to display the student roll list
void displayRollList() {
    if (head == NULL) {
        printf("The roll list is empty.\n");
        return;
    }
    printf("Student Roll List:\n");
    Student* temp = head;
    while (temp != NULL) {
        printf("Roll No: %d, Name: %s\n", temp->roll_no, temp->name);
        temp = temp->next;
    }
}

// Function to insert DSY girl students after Roll No 25
void insertDSYGirlsAfter25(int roll_no, char* name) {
    Student* temp = head;
    while (temp != NULL && temp->roll_no != 25) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Roll No 25 not found. Cannot insert DSY girls.\n");
        return;
    }

    Student* newNode = createNode(roll_no, name);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    } else {
        tail = newNode; // Update tail if inserted at the end
    }

    temp->next = newNode;
    printf("DSY Girl added after Roll No 25: Roll No: %d, Name: %s\n", roll_no, name);
}

// Function to insert DSY boys students at the end
void insertDSYBoysAtEnd(int roll_no, char* name) {
    addStudent(roll_no, name); // Use the same addStudent function
}

// Function to delete a student by roll number
void deleteStudent(int roll_no) {
    Student* temp = head;

    while (temp != NULL && temp->roll_no != roll_no) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with Roll No %d not found. Cannot delete.\n", roll_no);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // Update head if deleting the first node
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev; // Update tail if deleting the last node
    }

    free(temp);
    printf("Student with Roll No %d has been deleted from the roll list.\n", roll_no);
}

int main() {
    int choice, roll_no;
    char name[50];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display Roll List\n");
        printf("3. Insert DSY Girl Students After Roll No 25\n");
        printf("4. Insert DSY Boy Students at the End\n");
        printf("5. Delete Student by Roll No\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &roll_no);
                printf("Enter Name: ");
                getchar(); // Consume newline character
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove trailing newline
                addStudent(roll_no, name);
                break;

            case 2:
                displayRollList();
                break;

            case 3:
                printf("Enter Roll Number for DSY Girl: ");
                scanf("%d", &roll_no);
                printf("Enter Name: ");
                getchar();
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                insertDSYGirlsAfter25(roll_no, name);
                break;

            case 4:
                printf("Enter Roll Number for DSY Boy: ");
                scanf("%d", &roll_no);
                printf("Enter Name: ");
                getchar();
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                insertDSYBoysAtEnd(roll_no, name);
                break;

            case 5:
                printf("Enter Roll Number to Delete: ");
                scanf("%d", &roll_no);
                deleteStudent(roll_no);
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
