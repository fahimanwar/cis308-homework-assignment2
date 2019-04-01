#include <stdio.h>
#include "AVLTree.h"

void test1() {
    printf("\nTest 1\n");
    //9,5,10,2,6,11,1,3,4
    Node *root = insertNode(NULL, 9);
    root = insertNode(root, 5);
    root = insertNode(root, 10);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    printTree(root);
    printf("\n");
    root = deleteNode(root, 5);
    printTree(root);
    printf("\n");
    destroyTree(root);
}
void test2() {
    printf("\nTest 2\n");
    //9,5,10,2,6,11,1,3,4
    Node *root = insertNode(NULL, 9);
    root = insertNode(root, 5);
    root = insertNode(root, 10);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 6);
    root = insertNode(root, 11);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    printTree(root);
    printf("\n");
    root = deleteNode(root, 10);
    root = deleteNode(root, 1);
    root = deleteNode(root, 6);
    root = deleteNode(root, 5);
    printTree(root);
    printf("\n");
    destroyTree(root);
}
void test3() {
    printf("\nTest 3\n");
    //50,20,70,10,25,60,80,21,26
    Node *root = insertNode(NULL, 50);
    root = insertNode(root, 20);
    root = insertNode(root, 70);
    root = insertNode(root, 10);
    root = insertNode(root, 25);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    root = insertNode(root, 21);
    root = insertNode(root, 26);
    printTree(root);
    printf("\n");
    root = deleteNode(root, 80);
    root = deleteNode(root, 60);
    printTree(root);
    printf("\n");
    destroyTree(root);
}
void test4() {
    printf("\nTest 4\n");
    //20,15,14,50,30,70,60,80
    Node *root = insertNode(NULL, 20);
    root = insertNode(root, 15);
    root = insertNode(root, 14);
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    printTree(root);
    printf("\n");
    destroyTree(root);
}
void test5() {
    printf("\nTest 5\n");
    //20,15,50,14,30,70,60,80
    Node *root = insertNode(NULL, 20);
    root = insertNode(root, 15);
    root = insertNode(root, 50);
    root = insertNode(root, 14);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    printTree(root);
    printf("\n");
    root = deleteNode(root, 14);
    printTree(root);
    printf("\n");
    destroyTree(root);
}
void test6() {
    printf("\nTest 6\n");
    //5,4,6
    Node *root = insertNode(NULL, 5);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    printTree(root);
    printf("\n");
    root = deleteNode(root, 5);
    root = deleteNode(root, 4);
    root = deleteNode(root, 6);
    root = deleteNode(root, 1);
    printTree(root);
    printf("\n");
    destroyTree(root);
}
int main(void) {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}