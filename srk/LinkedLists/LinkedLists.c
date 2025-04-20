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

Node* deleteNode(Node* head, int position)
{
    Node* temp = head;
    Node* prev = NULL;

    // Base case if linked list is empty
    if (temp == NULL)
        return head;

    // Case 1: Head is to be deleted
    if (position == 1) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Case 2: Node to be deleted is in middle
    // Traverse till given position
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If given position is found, delete node
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    else {
        printf("Data not present\n");
    }

    return head;
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