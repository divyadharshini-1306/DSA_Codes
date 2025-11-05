#include <stdio.h>
#include <stdlib.h>

// --- 1. Node Structure ---
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int leftThread;  // 1 if left pointer is a thread (inorder predecessor), 0 if it's a child pointer
    int rightThread; // 1 if right pointer is a thread (inorder successor), 0 if it's a child pointer
} Node;

// --- Basic Utility Functions ---

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = 1;  // Initially, both pointers are threads (point to NULL/predecessor/successor)
    newNode->rightThread = 1;
    return newNode;
}

// Utility function to find the leftmost node in a subtree (used for traversal)
Node* leftMost(Node* n) {
    if (n == NULL) return NULL;
    // Keep traversing left until a left thread is found
    while (n->left != NULL && n->leftThread == 0) {
        n = n->left;
    }
    return n;
}

// --- 2. Search Operation ---
Node* search(Node* root, int key) {
    Node *curr = root;

    while (curr != NULL) {
        if (key == curr->data) {
            return curr; // Found
        } else if (key < curr->data) {
            // Move left only if it's a real child link (not a thread)
            if (curr->leftThread == 0) {
                curr = curr->left;
            } else {
                return NULL; // Thread encountered, key not in the search path
            }
        } else { // key > curr->data
            // Move right only if it's a real child link (not a thread)
            if (curr->rightThread == 0) {
                curr = curr->right;
            } else {
                return NULL; // Thread encountered, key not in the search path
            }
        }
    }
    return NULL; // Tree is empty or key not found
}

// --- 3. Inorder Traversal Operation (Non-Recursive) ---
void inorder(Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    // 1. Find the first node in inorder sequence (leftmost)
    Node *curr = leftMost(root);

    // 2. Traverse using threads and child pointers
    while (curr != NULL) {
        printf("%d ", curr->data); // Visit the current node

        // If the right pointer is a thread, follow it to the successor
        if (curr->rightThread == 1) {
            curr = curr->right;
        } else {
            // If the right pointer is a child, find the leftmost node in the right subtree
            curr = leftMost(curr->right);
        }
    }
    printf("\n");
}

// --- 4. Insert Operation ---
Node* insert(Node* root, int key) {
    Node *ptr = root;
    Node *parent = NULL;

    // 1. Find the insertion position (parent)
    while (ptr != NULL) {
        if (key == ptr->data) {
            printf("Duplicate key: %d ignored.\n", key);
            return root;
        }
        
        parent = ptr; // Keep track of the parent
        
        if (key < ptr->data) {
            if (ptr->leftThread == 0) {
                ptr = ptr->left;
            } else {
                break; // Position found at left of parent
            }
        } else { // key > ptr->data
            if (ptr->rightThread == 0) {
                ptr = ptr->right;
            } else {
                break; // Position found at right of parent
            }
        }
    }

    // 2. Create the new node
    Node *newNode = createNode(key);

    // 3. Perform the insertion and thread adjustments
    if (parent == NULL) {
        root = newNode; // Inserting into an empty tree
        // Threads already set to point to NULL (predecessor/successor)
    } 
    // Case: Insert as Left Child of parent
    else if (key < parent->data) {
        newNode->left = parent->left;  // New node's predecessor is parent's old predecessor
        newNode->right = parent;       // New node's successor is parent
        
        parent->leftThread = 0;        // Parent's left link is now a real child
        parent->left = newNode;
    } 
    // Case: Insert as Right Child of parent
    else {
        newNode->left = parent;        // New node's predecessor is parent
        newNode->right = parent->right; // New node's successor is parent's old successor
        
        parent->rightThread = 0;       // Parent's right link is now a real child
        parent->right = newNode;
    }
    
    return root;
}

// --- Main Function (Driver Code) ---
int main() {
    Node* root = NULL;

    // Insertion
    printf("Inserting nodes: 50, 30, 70, 20, 40, 60, 80\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 70); // Duplicate key check

    // Inorder Traversal
    printf("\nInorder Traversal (Non-Recursive):\n");
    printf("Expected: 20 30 40 50 60 70 80\n");
    printf("Result:   ");
    inorder(root);

    // Search Operation
    printf("\nSearch Operation:\n");
    
    int search_key_found = 40;
    Node* result_found = search(root, search_key_found);
    if (result_found != NULL) {
        printf("Searching for %d: Found.\n", search_key_found);
    } else {
        printf("Searching for %d: Not Found.\n", search_key_found);
    }

    int search_key_not_found = 99;
    Node* result_not_found = search(root, search_key_not_found);
    if (result_not_found != NULL) {
        printf("Searching for %d: Found.\n", search_key_not_found);
    } else {
        printf("Searching for %d: Not Found.\n", search_key_not_found);
    }

    // Note: A complete program would include a function to free the allocated memory.
    // For simplicity, memory deallocation (deletion) is omitted here.

    return 0;
}