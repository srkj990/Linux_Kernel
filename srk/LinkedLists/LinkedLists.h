#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

extern Node *CreatenewNode(int data);
extern void PrintLinkedList(Node *printNode);
extern Node* ReverseLinkedList(Node *reverseNode);
extern Node *insertAtFront(Node *headNode, int data);
extern Node *insertAtEnd(Node *headNode, int data);
extern Node *insertAtPosition(Node *headNode, int data, int position);
