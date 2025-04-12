/*
Includes definitions:
    - typedef struct Node {...} Node;
    - Node *createNode(int value);
    - void display_InOrder(Node *root);
    - void display_PreOrder(Node *root)
    - void display_PostOrder(Node *root)
    - Node *levelOrderInsertion(int size,int arr[size],int currIndex);
    - void deleteBST(Node **root,int value);
    - void insertBST(Node **root,int value);  
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the tree
typedef struct Node {
    int data;
    struct Node *left,*right;
} Node;

/* 
returns a pointer to a Node created with the passed input
    - value (int)   : data to hold in the Node
*/ 
Node * createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left= NULL;
    newNode->right= NULL;

    return newNode;
}

/* 
Prints the tree using "In-Order" traversal technique 
*/
void display_InOrder(Node *root) {
    if (root!=NULL) {
        display_InOrder(root->left);
        printf("%d\n",root->data);
        display_InOrder(root->right);
    }
}

/* 
Prints the tree using "pre-Order" traversal technique 
*/
void display_PreOrder(Node *root) {
    if (root!=NULL) {
        display_PreOrder(root->left);
        display_PreOrder(root->right);
        printf("%d\n",root->data);
    }
}

/* 
Prints the tree using "post-Order" traversal technique 
*/
void display_PostOrder(Node *root) {
    if (root!=NULL) {
        printf("%d\n",root->data);
        display_PostOrder(root->left);
        display_PostOrder(root->right);
    }
}

/*
Returns pointer to the constructed tree using level-Order Insertion technique. 
It takes the following parameters: 
    - size              : size of the tree / size of the arr being passed
    - arr (int[size])   : array of elements which will construct the tree
    - currIndex         : index to hold track of number of insertions made in the tree
*/
Node *levelOrderInsertion(int size,int arr[size],int currIndex) {
    
    // Base case
    if (currIndex>=size) return NULL;       

    Node *root = createNode(arr[currIndex]);
    
    root->left = levelOrderInsertion(size,arr,2*currIndex+1);
    root->right = levelOrderInsertion(size,arr,2*currIndex+2);

    return root;
}

/*
Inserts new value according to Binary Search Tree (BST) structure 
It takes the following parameters: 
    - root (Node **)    : double pointer of the root Node, in order to modify it
    - value (int)       : value to insert
*/
void insertBST(Node **root,int value) {

    // Dynamically creating a new Node with the passed value and assigning NULL to the ends
    Node *newNode = createNode(value);

    // if root is empty, assign new Node to the root itself
    if (*root==NULL) {
        *root = newNode;
        return;
    }

    // Else Iteratively finding the last Node and making the insertion
    Node *temp = *root;     
    Node *parent = NULL;

    while (temp) {
        parent = temp;
        if (value > temp->data) temp = temp->right;
        else temp = temp->left;
    }

    // Assignment
    if (value>parent->data) parent->right = newNode;
    else parent->left = newNode;
    return;
}

/*
Searches and then Deletes the value passed as a parameter in the Binary Search Tree (BST) structure 
It takes the following parameters: 
    - root (Node **)    : double pointer of the root Node, in order to modify it
    - value (int)       : value to delete
*/
void deleteBST(Node **root,int value) {
    if (*root == NULL) return;  // Case-0: Tree is empty

    Node *temp = *root;
    Node *parent = NULL;

    // Finding the Node to be deleted
    while (temp != NULL && temp->data != value) {
        parent = temp;
        if (value > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }

    // Case-1: Value not found
    if (temp == NULL) return;

    // Value is found and now stored in temp //

    // Case-2: temp Node has no children (leaf Node)
    if (temp->left == NULL && temp->right == NULL) {
        if (parent == NULL)
            *root = NULL;  // Deleting the root itself 
        else if (parent->left == temp)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(temp);
    }

    // Case-3: Node has one child
    else if (temp->left == NULL || temp->right == NULL) {
        Node *child = (temp->left != NULL) ? temp->left : temp->right;

        if (parent == NULL) {
            *root = child;  // If deleting the root Node
        } else if (parent->left == temp) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(temp);
    }

    // Case-4: Node has two children
    else {
        Node *successor = temp->right;
        Node *successorParent = temp;

        // Find the in-order successor (leftmost Node in right subtree)
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace temp's data with successor's data
        temp->data = successor->data;

        // Delete the successor (it has at most one child)
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }

        free(successor);
    }
}

