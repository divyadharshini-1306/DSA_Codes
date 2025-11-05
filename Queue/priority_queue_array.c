#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct PriorityQueue
{
    int data;
    int priority;

}pq[MAX];

int front,rear;

void create()
{
    front=-1;
    rear=-1;

}
void enqueue(int data,int priority)
{
    if(rear==MAX-1)
    {
        printf("Queue Overflow\n");
        return ;
    }

//if queue is empty
if(front==-1)
{
    front=rear=0;
    pq[rear].data=data;
    pq[rear].priority=priority;
}
else
{
    int i;
    for(i=rear;i>=front && pq[i].priority<priority;i--) //for ascending we will have same loop pq[i].priority>priority
    {
        pq[i+1]=pq[i]; //shifting
    }

pq[i+1].data=data;
pq[i+1].priority=priority;
rear++;
}
printf("Inserted %d with priority %d\n",data,priority);
}
int dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    } 

    int item = pq[front].data;
    printf("Deleted %d with priority %d\n", pq[front].data, pq[front].priority);

    if (front == rear) {
        front = rear = -1; // Reset queue if last element removed
    } else {
        front++;
    }
    return item;
}

// Display function
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("\nPriority Queue (Descending Order):\n");
    for (int i = front; i <= rear; i++) {
        printf("Value: %d | Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    create();  // Initialize the queue

    enqueue(10, 2);
    enqueue(5, 1);
    enqueue(20, 3);
    enqueue(15, 2);

    display();

    dequeue();
    display();

    return 0;
}







