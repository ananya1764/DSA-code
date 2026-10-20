
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *create()
{
    struct node *head, *temp, *newnode;
    int n, i;

    head = (struct node *)malloc(sizeof(struct node));
    head->next = head;
    temp = head;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &newnode->coeff, &newnode->exp);

        newnode->next = head;
        temp->next = newnode;
        temp = newnode;
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp;

    temp = head->next;

    if (temp == head)
    {
        printf("0");
        return;
    }

    while (temp != head)
    {
        printf("%dx^%d", temp->coeff, temp->exp);

        temp = temp->next;

        if (temp != head)
            printf(" + ");
    }
}

struct node *add(struct node *p1, struct node *p2)
{
    struct node *head, *temp, *newnode;
    struct node *a, *b;

    head = (struct node *)malloc(sizeof(struct node));
    head->next = head;
    temp = head;

    a = p1->next;
    b = p2->next;

    while (a != p1 && b != p2)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (a->exp == b->exp)
        {
            newnode->coeff = a->coeff + b->coeff;
            newnode->exp = a->exp;
            a = a->next;
            b = b->next;
        }
        else if (a->exp > b->exp)
        {
            newnode->coeff = a->coeff;
            newnode->exp = a->exp;
            a = a->next;
        }
        else
        {
            newnode->coeff = b->coeff;
            newnode->exp = b->exp;
            b = b->next;
        }

        if (newnode->coeff != 0)
        {
            newnode->next = head;
            temp->next = newnode;
            temp = newnode;
        }
        else
        {
            free(newnode);
        }
    }

    while (a != p1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = a->coeff;
        newnode->exp = a->exp;
        newnode->next = head;
        temp->next = newnode;
        temp = newnode;
        a = a->next;
    }

    while (b != p2)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = b->coeff;
        newnode->exp = b->exp;
        newnode->next = head;
        temp->next = newnode;
        temp = newnode;
        b = b->next;
    }

    return head;
}

int main()
{
    struct node *p1, *p2, *p3;

    printf("Enter first polynomial (terms in descending exponent order):\n");
    p1 = create();

    printf("Enter second polynomial (terms in descending exponent order):\n");
    p2 = create();

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("\nSecond Polynomial: ");
    display(p2);

    p3 = add(p1, p2);

    printf("\nResultant Polynomial: ");
    display(p3);

    printf("\n");

    return 0;
}
