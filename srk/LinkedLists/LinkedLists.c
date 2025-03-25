/******************************************************************************

*******************************************************************************/
#include "LinkedLists.h"

Node *CreatenewNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void PrintLinkedList(Node *printNode)
{   
    printf("Printing the linked List....\n");
    while(printNode)
    {
        printf("%d\n", printNode->data);
        printNode = printNode->next;
    }
}
Node *insertAtFront(Node *headNode, int data)
{
    printf("Inserting %d at front\n",data);
    Node *newNode = CreatenewNode(data);
    newNode->next = headNode;
    headNode = newNode;
    return headNode;
}
Node *insertAtPosition(Node *headNode, int data, int position)
{
    int count = 1;
    printf("Inserting %d at position %d\n",data, position);
    Node *newNode = CreatenewNode(data);
    if(headNode == NULL)
    {
        return newNode;
    }
    Node *current = headNode;
    if(position == 1u)
    {
        return insertAtFront(headNode, data);
    }
    else
    {
        while (current)
        {
            count++;
            if (count == position)
            {
                newNode->next = current->next;
                current->next = newNode;
                return headNode;
            }
            else
            {
                current = current->next;
            }
        }
    }
    printf("Invalid Position!\n");
    exit(EXIT_FAILURE);

}
Node *insertAtEnd(Node *headNode, int data)
{
    printf("Inserting %d at end\n",data);
    Node *newNode = CreatenewNode(data);
    Node *lastNode = headNode;
    while(lastNode->next)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    return headNode;
}

Node* ReverseLinkedList(Node *reverseNode)
{
    printf("Reversing the Linked List\n");
    Node *prev = NULL, *next, *current = reverseNode;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}