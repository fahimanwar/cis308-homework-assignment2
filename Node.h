//
// Created by Fahim Anwar on 3/30/2019.
//

#ifndef UNTITLED2_NODE_H
#define UNTITLED2_NODE_H

typedef struct Node{
    int Key;
    int Height;
    struct Node * Left;
    struct Node * Right;
}Node;

Node * createNode(int);

#endif //UNTITLED2_NODE_H
