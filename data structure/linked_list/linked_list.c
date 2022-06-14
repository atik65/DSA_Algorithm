#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_node(int data, Node *next)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Error!! Could not create a new node\n");
        exit(1);
    }

    new_node->data = data;
    new_node->next = next;
    return new_node;
}

int main()
{
    Node *n = create_node(10, NULL);
    printf("%d\n", n->data);

    return 0;
}