#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char name[100];
    int salary;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(const char* name, int salary) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->name, name);
    newNode->salary = salary;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, const char* name, int salary) {
    if (root == NULL) {
        return createNode(name, salary);
    }
    if (salary < root->salary) {
        root->left = insert(root->left, name, salary);
    } else {
        root->right = insert(root->right, name, salary);
    }
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Name: %s, Salary: %d\n", root->name, root->salary);
        inorderTraversal(root->right);
    }
}

int findMaxSalary(TreeNode* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->salary;
}

int findMinSalary(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->salary;
}

int calculateTotalExpenses(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return root->salary + calculateTotalExpenses(root->left) + calculateTotalExpenses(root->right);
}

int main() {
    TreeNode* root = NULL;
    int numEmployees;

    // Take input for number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    for (int i = 0; i < numEmployees; i++) {
        char name[100];
        int salary;

        printf("Enter name of employee %d: ", i + 1);
        scanf("%s", name);
        printf("Enter salary of employee %d: ", i + 1);
        scanf("%d", &salary);


        root = insert(root, name, salary);
    }

    // Inorder traversal (sorted by salary)
    printf("\nEmployees sorted by salary:\n");
    inorderTraversal(root);


    int maxSalary = findMaxSalary(root);
    int minSalary = findMinSalary(root);
    printf("\nMaximum salary: %d\n", maxSalary);
    printf("Minimum salary: %d\n", minSalary);

    int totalExpenses = calculateTotalExpenses(root);
    printf("\nTotal monthly expenses: %d\n", totalExpenses);

    return 0;
}
