#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next)
{

    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Error!! Memory allocation failed..\n");
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;
    return new_node;
}

Node *prepend(Node *head, int item)
{

    Node *new_node = create_node(item, NULL);

    new_node->next = head;
    return new_node;
}

Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL);

    if (head == NULL)
    {
        return new_node;
    }

    Node *current_node = head;

    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    return head;
}

void insert(Node *node, int item)
{

    Node *new_node = create_node(item, node->next);
    node->next = new_node;
}

Node *delete_node(Node *head, Node *node)
{
    if (head == node)
    {
        head = node->next;
        free(node);
        return head;
    }

    Node *current_node = head;

    while (current_node->next != NULL)
    {

        if (current_node->next == node)
        {

            break;
        }
        current_node = current_node->next;
    }

    if (current_node == NULL)
    {
        return head;
    }

    current_node->next = node->next;
    free(node);
    return head;
}

Node *search(Node *head, int item)
{
    Node *current_node = head;

    while (current_node != 0)
    {

        if (current_node->data == item)
        {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

void print_linked_list(Node *head)
{
    Node *current_node = head;
    while (current_node != NULL)
    {

        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

Node *reverse(Node *head)
{
    Node *current, *next, *prev;
    current = next = head;
    prev = NULL;
    while (next != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int size(Node *head)
{
    Node *current_node = head;
    int size = 0;
    while (current_node != NULL)
    {
        size++;
        current_node = current_node->next;
    }

    return size;
}

int compare(Node *head1, Node *head2)
{
    int size1 = size(head1);
    int size2 = size(head2);

    if (size1 != size2)
    {
        return -1;
    }

    Node *current_node1 = head1;
    Node *current_node2 = head2;
    int count = 0;
    while (count < size1)
    {
        if (current_node1->data != current_node2->data)
        {
            return -1;
        }
        current_node1 = current_node1->next;
        current_node2 = current_node2->next;
        count++;
    }

    return 1;
}
int main()
{

    Node *head = create_node(0, NULL);
    Node *head2 = create_node(0, NULL);
    head2 = append(head2, 200);
    head2 = append(head2, 0);
    head2 = append(head2, 100);
    // head2 = append(head2, 100);
    head = prepend(head, 0);
    head = append(head, 100);
    insert(head, 200);

    // head = delete_node(head, search(head, 10));
    print_linked_list(head);

    // head = reverse(head);
    print_linked_list(head);
    print_linked_list(head2);
    printf("%d\n", compare(head, head2));
    return 0;
}
