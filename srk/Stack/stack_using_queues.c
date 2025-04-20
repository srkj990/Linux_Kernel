//{ Driver Code Starts
// Initial Template for C

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is empty when size is 0
int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue *queue, int item)
{
    if (queue->size == queue->capacity) 
    {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from queue.
// It changes front and size
void dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
}

// Function to get front of queue
int front(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get size of queue
int size(struct Queue *queue)
{
    return queue->size;
}

// } Driver Code Ends

void swapQueues(struct Queue **q1, struct Queue **q2)
{
    struct Queue *temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}
void push(struct Queue *q1, struct Queue *q2, int num)
{
    // code here
    enqueue(q2, num);
    while (!isEmpty(q1))
    {
        enqueue(q2, front(q1));
        dequeue(q1);
    }
    //swapQueues(&q1, &q2);
        // Now swap the names (q1 becomes the main queue with new element at front)
        struct Queue temp = *q1;
        *q1 = *q2;
        *q2 = temp;
}

int pop(struct Queue *q1)
{
    int retVal = 0;
    if (isEmpty(q1))
    {
        return -1;
    }
    else
    {
        retVal = front(q1);
        dequeue(q1);
    }
    return retVal;
    // code here
}

//{ Driver Code Starts.

int main()
{

    int t;
    t = 1;
    while (t--)
    {
        int n;
        printf("Enter No of operations : \n");
        scanf("%d", &n);
        printf("No of operations : %d\n", n);
        struct Queue *q1 = createQueue(n);
        struct Queue *q2 = createQueue(n);
        while (n--)
        {
            int opt;
            printf("push(1) or pop(2) \n");
            scanf("%d", &opt);
            
            if (opt == 1)
            {
                int x;
                printf("Enter the element to push : \n");
                scanf("%d", &x);
                push(q1, q2, x);
                printf("pushed %d\n", x);
            }
            else
            {
                printf("Popped Item : %d ", pop(q1));

            }
        }
        printf("\n");

        printf("~%s", "\n");
    }
    return 0;
}

// } Driver Code Ends