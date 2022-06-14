#include <stdio.h>
#define STACK_MAX 5

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
    // push(&newStack, 50);

    pop(&newStack);

    printf("%d\n", newStack.top);
    return 0;
}