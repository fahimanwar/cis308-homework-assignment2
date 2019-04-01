//
// Created by Fahim Anwar on 3/30/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "AVLTree.h"

int getHeight(Node * node){ //CORRECT
    if(node==NULL)
        return(0);
    else
        return node->Height;
}

void updateHeight(Node * node){ //CORRECT
    int left, right;
    left = getHeight(node->Left);
    right = getHeight(node->Right);
    if(left > right){
        node->Height = left + 1;
    }
    if(right > left){
        node->Height = right + 1;
    }
}

Node * rotateRight(Node * a){ //Correct
    printf("Single Right Rotation. \n");
    Node *newroot = a->Left;
    Node *oldRight = a->Left->Right;
    newroot->Right = a;
    newroot->Right->Left = oldRight;
    updateHeight(a);
    updateHeight(newroot);
    return(newroot);
}

Node * rotateLeft(Node * a){ //Correct
    printf("Single Left Rotation. \n");
    Node *b;
    b=a->Right;
    a->Right=a->Right->Left;
    b->Left=a;
    updateHeight(a);
    updateHeight(b);
    return(b);
}

Node * doubleRotateRight(Node * a){ //Correct
    printf("--Double Right Rotation-- \n");
    a->Left=rotateLeft(a->Left);
    a=rotateRight(a);
    return(a);
}

Node * doubleRotateLeft(Node * a){ //Correct
    printf("--Double Left Rotation-- \n");
    a->Right=rotateRight(a->Right);
    a=rotateLeft(a);
    return(a);
}

int getBalanceFactor(Node * root){ //Correct
    int h;
    if(root != NULL){
        h = (getHeight(root->Left) - getHeight(root->Right));
        return h;
    }
    return 0;
}

Node * getSuccessor(Node * root){ //Correct

    if(root == NULL)
        return NULL;
    else if(root->Left == NULL)
        return root;
    else
        return getSuccessor(root->Left);
}

Node * balanceTreeAfterInsert(Node *root, int key){ //Correct
    if(getBalanceFactor(root) > 1){
        if(key < root->Left->Key){
            return rotateRight(root);
        }
    }
    if(getBalanceFactor(root) < -1){
        if(key > root->Right->Key){
            return rotateLeft(root);
        }
    }
    if(getBalanceFactor(root) > 1){
        if(key > root->Left->Key){
            return doubleRotateRight(root);
        }
    }
    if(getBalanceFactor(root) <- 1){
        if(key < root->Right->Key){
            return doubleRotateLeft(root);
        }
    }
    return root;
}

Node * insertNode(Node * root, int key){ //Correct
    if(root==NULL)
    {
        root = createNode(key);
        return root;
    }
    else
    if(key > root->Key)
    {
        root->Right=insertNode(root->Right,key);
    }
    else
    if(key < root->Key)
    {
        root->Left=insertNode(root->Left,key);
    }
    else if(key == root->Key){
        printf("Cannot insert duplicate key.");
        printf("\n");
        return root;
    }
    updateHeight(root);
    return balanceTreeAfterInsert(root, key);
}

Node * balanceTreeAfterDelete(Node *root){ //Correct
    int bfRoot, bfLeft, bfRight;
    bfRoot = getBalanceFactor(root);
    bfLeft = getBalanceFactor(root->Left);
    bfRight =getBalanceFactor(root->Right);

    if(bfRoot > 1){
        if(bfLeft >= 0){
            return rotateRight(root);
        }
    }
    if(bfRoot < -1){
        if(bfRight <= 0){
            return rotateLeft(root);
        }
    }
    if(bfRoot > 1){
        if(bfLeft < 0){
            return doubleRotateRight(root);
        }
    }
    if(bfRoot < -1){
        if(bfRight > 0){
            return doubleRotateLeft(root);
        }
    }
    return root;
}

Node * deleteNode(Node *root, int key){ //Correct
    if (root == NULL)
        return NULL;
    if (key < root->Key)
        root->Left = deleteNode(root->Left, key);
    else if(key > root->Key)
        root->Right = deleteNode(root->Right, key);
    else
    {
        if(root->Key == key) {

            if (root->Left == NULL && root->Right == NULL)
            {
                free(root);
                return NULL;
            }
            else if(root->Left != NULL && root->Right != NULL)
            {
                Node *temp = getSuccessor(root->Right);
                root->Key = temp->Key;
                root->Right = deleteNode(root->Right, temp->Key);
            }
            else if (root->Left != NULL || root->Right != NULL)
            {
                if (root->Left != NULL && root->Right == NULL)
                {
                    Node *oldRoot = root;
                    root = root->Left;
                    free(oldRoot);
                }
                else
                    {
                    Node *oldRoot = root;
                    root = root->Right;
                    free(oldRoot);
                }
            }
        }
    }
    updateHeight(root);
    return balanceTreeAfterDelete(root);
    }


void printTree(Node *root){ //Correct
    printf("%d ",root->Key);
    if(root->Left != NULL){
        printTree(root->Left);
    }

    if(root->Right != NULL){
        printTree(root->Right);
    }
}

void destroyTree(Node * root){ //Incorrect
    if(root->Left != NULL) {
        destroyTree(root->Left);
    }
    if(root->Right != NULL) {
        destroyTree(root->Right);
    }
    free(root);
}

