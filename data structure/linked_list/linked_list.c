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

int main()
{

    Node *head = create_node(10, NULL);
    head = prepend(head, 20);
    head = append(head, 100);
    insert(head, 200);

    head = delete_node(head, search(head, 10));
    print_linked_list(head);

    print_linked_list(head);

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node Node;

// struct node
// {
//     int data;
//     Node *next;
// };

// Node *create_node(int data, Node *next)
// {

//     Node *new_node = (Node *)malloc(sizeof(Node));

//     if (new_node == NULL)
//     {
//         printf("Error!! No memory allocated!!\n");
//         exit(1);
//     }

//     new_node->data = data;
//     new_node->next = next;
//     return new_node;
// }

// Node *delete_node(Node *head, Node *node)
// {
//     if (node == head)
//     {
//         head = node->next;
//         free(node);
//         return head;
//     };

//     Node *current_node = head;
//     while (current_node->next != NULL)
//     {
//         if (current_node->next == node)
//         {
//             break;
//         }
//         current_node = current_node->next;
//     }

//     if (current_node == NULL)
//     {
//         return head;
//     }

//     current_node->next = node->next;
//     free(node);
//     return head;
// }

// Node *prepend(Node *head, int item)
// {

//     Node *new_node = create_node(item, head);
//     return new_node;
// }

// Node *append(Node *head, int item)
// {
//     Node *new_node = create_node(item, NULL);

//     if (head == NULL)
//     {
//         return new_node;
//     }

//     Node *current_node = head;

//     while (current_node->next != NULL)
//     {
//         current_node = current_node->next;
//     }

//     current_node->next = new_node;
//     return head;
// }

// void insert(Node *node, int item)
// {
//     Node *new_node = create_node(item, node->next);
//     node->next = new_node;
// }

// void print_linked_list(Node *head)
// {
//     Node *current_node = head;

//     while (current_node != NULL)
//     {
//         printf("%d ", current_node->data);
//         current_node = current_node->next;
//     }
//     printf("\n");
// }

// Node *search(Node *head, int item)
// {
//     Node *current_node = head;

//     while (current_node->next != NULL)
//     {
//         if (current_node->next->data == item)
//         {
//             return current_node->next;
//         };
//         current_node = current_node->next;
//     }
// }

// int main()
// {

//     Node *head = create_node(0, NULL);

//     head = prepend(head, 20);

//     print_linked_list(head);

//     head = append(head, 50);

//     print_linked_list(head);

//     insert(head, 100);
//     head = prepend(head, 999);
//     print_linked_list(head);

//     delete_node(head, search(head, 100));
//     print_linked_list(head);

//     return 0;
// }
