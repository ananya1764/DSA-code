
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int precedence(char x)
{
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/' || x == '%')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[])
{
    char postfix[MAX];
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && peek() != '(' &&
                   (precedence(peek()) > precedence(infix[i]) ||
                   (precedence(peek()) == precedence(infix[i]) &&
                    infix[i] != '^')))
            {
                postfix[j++] = pop();
            }

            push(infix[i]);
        }

        i++;
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main()
{
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    infixToPostfix(infix);

    return 0;
}

