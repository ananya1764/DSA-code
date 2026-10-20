
#include <stdio.h>

#define MAX 5

struct job
{
    int jobid;
    char title[50];
};

struct job queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is full.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;

    printf("Enter Job ID: ");
    scanf("%d", &queue[rear].jobid);

    printf("Enter Document Title: ");
    scanf(" %49[^\n]", queue[rear].title);

    printf("Print job added successfully.\n");
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Processing Job ID: %d\n", queue[front].jobid);
    printf("Document Title: %s\n", queue[front].title);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("Print job completed.\n");
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("No pending print jobs.\n");
        return;
    }

    printf("\nPending Print Jobs:\n");

    i = front;

    while (1)
    {
        printf("Job ID: %d, Document: %s\n",
               queue[i].jobid, queue[i].title);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n--- Printer Queue Manager ---\n");
        printf("1. Add Print Job (Enqueue)\n");
        printf("2. Process Print Job (Dequeue)\n");
        printf("3. Display Pending Print Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (ch != 4);

    return 0;
}
