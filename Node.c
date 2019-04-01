//
// Created by Fahim Anwar on 3/30/2019.
//

#include <stdio.h>
#include "Node.h"
#include "AVLTree.h"
#include "stdlib.h"

Node * createNode(int key){
    Node * root = NULL;
    root = malloc(sizeof(Node));

    root->Left = NULL;
    root->Right = NULL;
    root->Height = 1;
    root->Key = key;
}