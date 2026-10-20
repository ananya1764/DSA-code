
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int regno;
    char name[50];
    struct node *next;
};

struct node *head = NULL;

void add()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Registration Number: ");
    scanf("%d", &newnode->regno);

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", newnode->name);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Student added successfully.\n");
}

void removeStudent()
{
    struct node *temp, *prev;
    int r;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter Registration Number to remove: ");
    scanf("%d", &r);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->regno != r)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Student not found.\n");
    }
    else if (prev == NULL)
    {
        head = temp->next;
        free(temp);
        printf("Student removed successfully.\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        printf("Student removed successfully.\n");
    }
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("\nRegistration No.\tName\n");

    while (temp != NULL)
    {
        printf("%d\t\t\t%s\n", temp->regno, temp->name);
        temp = temp->next;
    }
}

void count()
{
    struct node *temp;
    int c = 0;

    temp = head;

    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    printf("Total Participants = %d\n", c);
}

void sort()
{
    struct node *i, *j;
    int r;
    char n[50];

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->regno > j->regno)
            {
                r = i->regno;
                i->regno = j->regno;
                j->regno = r;

                strcpy(n, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, n);
            }
        }
    }

    printf("List sorted by Registration Number.\n");
}

void reverse()
{
    struct node *prev = NULL, *curr = head, *nextnode;

    while (curr != NULL)
    {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }

    head = prev;

    printf("List reversed successfully.\n");
}

int main()
{
    int ch;

    do
    {
        printf("\n--- Workshop Enrollment System ---\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display List\n");
        printf("4. Count Total Participants\n");
        printf("5. Sort List\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                add();
                break;

            case 2:
                removeStudent();
                break;

            case 3:
                display();
                break;

            case 4:
                count();
                break;

            case 5:
                sort();
                break;

            case 6:
                reverse();
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (ch != 7);

    return 0;
}
