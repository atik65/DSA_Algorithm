#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node *prev;
    Node *next;
};

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory Allocation Failed!! No node Created...\n");
        exit(1);
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item);
    new_node->next = head;
    return new_node;
}

Node *print_linked_list(Node *head)
{
    Node *current_node = head;

    while (current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

Node *append(Node *head, int item)
{
    Node *new_node = create_node(item);
    Node *current_node = head;

    if (head == NULL)
    {
        return new_node;
    }
    while (current_node->next != NULL)
    {

        current_node = current_node->next;
    }
    new_node->prev = current_node;
    current_node->next = new_node;
    return head;
}

Node *insert(Node *node, int item)
{
    Node *new_node = create_node(item);
    node->next->prev = new_node;
    new_node->next = node->next;
    new_node->prev = node;
    node->next = new_node;
    return new_node;
}

Node *delete (Node *head, Node *node)
{
    if (node == head)
    {
        node->prev = NULL;
        head = node->next;
        free(node);
        return head;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return head;
}

int count(Node *head)
{
    int count = 0;
    Node *current_node = head;
    if (head == NULL)
    {
        return count;
    }
    while (current_node != NULL)
    {
        count++;
        current_node = current_node->next;
    }

    return count;
}
Node *reverse(Node *head)
{
    Node *current = head;
    Node *next_node;
    Node *temp_head;

    while (current != 0)
    {
        temp_head = current;
        next_node = current->next;

        current->next = current->prev;
        current->prev = next_node;
        current = next_node;
    }
    return temp_head;
}

int main()
{
    Node *head;
    head = create_node(10);

    head = prepend(head, 20);

    head = append(head, 100);

    Node *test = insert(head, 500); // here head is pointing 20
    // head = delete (head, test);
    print_linked_list(head);
    head = reverse(head);
    print_linked_list(head);
    printf("total length is = %d\n", count(head));
}