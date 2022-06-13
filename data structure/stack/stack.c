#include <stdio.h>
#define STACK_MAX 10

typedef struct
{
    int top;
    int data[STACK_MAX];
} Stack;

void push(Stack *s, int item)
{
    if (s->top < STACK_MAX)
    {

        s->data[s->top] = item;
        s->top++;
    }
    else
    {

        printf("Stack is full!!");
    }
}

int pop(Stack *s)
{

    if (s->top == 0)
    {
        printf("Stack is Empty!!");
        return -1;
    }
    else
    {
        s->top--;
        return s->data[s->top];
    }
}

int main()
{

    Stack newStack;
    newStack.top = 0;
    int i = 0;

    push(&newStack, 10);
    push(&newStack, 20);
    push(&newStack, 30);
    push(&newStack, 40);
    push(&newStack, 50);
    push(&newStack, 60);
    push(&newStack, 70);
    push(&newStack, 80);
    push(&newStack, 90);
    push(&newStack, 100);

    pop(&newStack);

    for (i = 0; i < newStack.top; i++)
    {
        printf("%d\t", newStack.data[i]);
    }

    return 0;
}