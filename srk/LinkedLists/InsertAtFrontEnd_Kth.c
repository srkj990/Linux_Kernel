#include "LinkedLists.h"

int main()
{
    Node *head = CreatenewNode(100);
    head->next = CreatenewNode(200);
    head->next->next = CreatenewNode(300);
    head->next->next->next = CreatenewNode(400);
    
    PrintLinkedList(head);
    head = insertAtFront(head, 50);
    PrintLinkedList(head);
    head = insertAtEnd(head, 500);
    PrintLinkedList(head);
    head = insertAtPosition(head, 350, 1);
    PrintLinkedList(head);
}