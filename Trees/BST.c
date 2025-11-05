#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* create(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert a node into BST
struct node* insert(struct node *root, int value) {
    if (root == NULL) {
        return create(value);
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root; // unchanged root
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search in BST
struct node* search(struct node *root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find minimum node
struct node* findMin(struct node *root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
struct node* deleteNode(struct node *root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct node *root = NULL;

    // Insert nodes
    root = insert(root, 40);
    root = insert(root, 41);
    root = insert(root, 42);
    root = insert(root, 43);
    root = insert(root, 44);
    root = insert(root, 45);
    root = insert(root, 46);

    // Traversals
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    // Search
    int searchValue = 42;
    struct node *found = search(root, searchValue);
    if (found != NULL)
        printf("Element %d found in BST.\n", searchValue);
    else
        printf("Element %d not found in BST.\n", searchValue);

    // Delete
    root = deleteNode(root, 42);
    printf("Inorder Traversal after deleting 42: ");
    inorder(root);
    printf("\n");

    return 0;
}
