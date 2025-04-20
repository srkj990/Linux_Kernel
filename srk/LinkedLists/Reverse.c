#include "LinkedLists.h"
int main()
{
    Node* next; 
    Node* prev=NULL;
    
    Node *head = CreatenewNode(100);
    head->next = CreatenewNode(200);
    head->next->next = CreatenewNode(300);
    head->next->next->next = CreatenewNode(400);
    Node *current = head;
    
    PrintLinkedList(current);
    
    current = ReverseLinkedList(current);
    PrintLinkedList(current);

    head = deleteNode(current, 2);
    PrintLinkedList(head);
    
    return 0;
}