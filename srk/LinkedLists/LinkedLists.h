#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *CreatenewNode(int data);
void PrintLinkedList(Node *printNode);
Node* ReverseLinkedList(Node *reverseNode);
Node *insertAtFront(Node *headNode, int data);
Node *insertAtEnd(Node *headNode, int data);
Node *insertAtPosition(Node *headNode, int data, int position);
Node* deleteNode(Node* head, int position);
