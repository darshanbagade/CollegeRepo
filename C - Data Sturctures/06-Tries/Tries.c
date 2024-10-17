#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

TrieNode *createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    if (node) {
        node->isEndOfWord = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

void insertKey(TrieNode *root, const char *key) {
    TrieNode *current = root;
    while (*key) {
        int index = (*key >= 'a' && *key <= 'z') ? *key - 'a' : *key - 'A';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        key++;
    }
    current->isEndOfWord = 1;
}

int searchKey(TrieNode *root, const char *key) {
    TrieNode *current = root;
    while (*key) {
        int index = (*key >= 'a' && *key <= 'z') ? *key - 'a' : *key - 'A';
        if (!current->children[index]) {
            return 0;
        }
        current = current->children[index];
        key++;
    }
    return current->isEndOfWord;
}

void freeTrie(TrieNode *root) {
    if (!root) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(root->children[i]);
    }
    free(root);
}

void loadKeysFromFile(const char *filename, TrieNode *root) {
    FILE *file = fopen(filename, "r");
    char key[100];
    
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    
    while (fscanf(file, "%s", key) != EOF) {
        insertKey(root, key);
    }
    
    fclose(file);
}

void searchUserKeys(TrieNode *root) {
    char input[100];
    while (1) {
        printf("Enter a key to search (or type 'exit' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) break;
        
        if (searchKey(root, input)) {
            printf("Key '%s' found in trie.\n", input);
        } else {
            printf("Key '%s' not found in trie.\n", input);
        }
    }
}

void searchPredefinedKeys(TrieNode *root) {
    const char *keysToSearch[] = {"and", "bat", "ball", "book", "cot", 
                                   "cotton", "internet", "interview", 
                                   "joy", "job", "King", "Lion", 
                                   "man", "mango", "manage"};
    
    for (int i = 0; i < sizeof(keysToSearch) / sizeof(keysToSearch[0]); i++) {
        if (searchKey(root, keysToSearch[i])) {
            printf("Key '%s' found in trie.\n", keysToSearch[i]);
        } else {
            printf("Key '%s' not found in trie.\n", keysToSearch[i]);
        }
    }
}

int main() {
    TrieNode *root = createNode();
    
    loadKeysFromFile("keys.txt", root);
    searchUserKeys(root);
    searchPredefinedKeys(root);
    
    freeTrie(root);
    return 0;
}