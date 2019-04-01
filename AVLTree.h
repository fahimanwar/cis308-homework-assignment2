//
// Created by Fahim Anwar on 3/30/2019.
//

#ifndef UNTITLED2_AVLTREE_H
#define UNTITLED2_AVLTREE_H
#include "Node.h"

Node * insertNode(Node *, int);
Node * deleteNode(Node *, int);
Node * rotateRight(Node *);
Node * doubleRotateRight(Node *);
Node * rotateLeft(Node *);
Node * doubleRotateLeft(Node *);
Node * getSuccessor(Node *);
int getHeight(Node *);
void updateHeight(Node *);
Node * balanceTreeAfterInsert(Node *, int);
Node * balanceTreeAfterDelete(Node *);
int getBalanceFactor(Node *);
void printTree(Node *);
void destroyTree(Node *);

#endif //UNTITLED2_AVLTREE_H
