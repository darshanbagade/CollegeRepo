/*
    Program based on tries :

    i. Create a text file containing keys{“and”, “bat”, “ ball”,
        “book”,“cot”, “cotton”, “internet”, “interview”, “joy”,
        “job”, “King”, “Lion”, “man”, “mango”, “manage”}
        separated by tab and then read those keys and insert them
        in trie and search the key which is accepted as input from
        user

    ii. Read the keys from char array which is already given and
        search the keys which are accepted as input from user

    iii. Read the keys from char array and search those keys
        which are given in text file

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Definition of TrieNode
typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

// Create a new Trie Node
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

// Insert a key into the Trie
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

// Search for a key in the Trie
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

// Free the memory used by the Trie
void freeTrie(TrieNode *root) {
    if (!root) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(root->children[i]);
    }
    free(root);
}

// Load keys from a file and insert into the Trie
void loadKeysFromFile(const char *filename, TrieNode *root) {
    FILE *file = fopen(filename, "r");
    char buffer[100];

    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    printf("Loading keys from file '%s':\n", filename);
    while (fscanf(file, "%s", buffer) != EOF) {
        printf(" - Inserting key: %s\n", buffer);
        insertKey(root, buffer);
    }

    printf("All keys from '%s' have been loaded.\n", filename);
    fclose(file);
}

// Search for user-input keys in the Trie
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

// Search predefined keys in the Trie
void searchPredefinedKeys(TrieNode *root) {
    const char *keysToSearch[] = {"and", "bat", "ball", "book", "cot",
                                  "cotton", "internet", "interview",
                                  "joy", "job", "King", "Lion",
                                  "man", "mango", "manage"};

    printf("Searching predefined keys:\n");
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

    const char *filename = "keys.txt";
    loadKeysFromFile(filename, root);

    searchUserKeys(root);

    searchPredefinedKeys(root);

    freeTrie(root);
    return 0;
}







