#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;

struct node
{
    int data;

    Node *left;
    Node *right;
};

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Error!! Failed to create node");
        exit(1);
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_node_to_left(Node *node, Node *child)
{
    node->left = child;
}

void add_node_to_right(Node *node, Node *child)
{
    node->right = child;
}

Node *create_tree()
{
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    Node *one = create_node(1);
    Node *six = create_node(6);
    Node *five = create_node(5);
    Node *ten = create_node(10);
    Node *eight = create_node(8);
    Node *three = create_node(3);
    Node *four = create_node(4);

    add_node_to_left(two, seven);
    add_node_to_right(two, nine);
    add_node_to_left(seven, one);
    add_node_to_right(seven, six);
    add_node_to_left(six, five);
    add_node_to_right(six, ten);
    add_node_to_left(nine, eight);
    add_node_to_left(eight, three);
    add_node_to_right(eight, four);

    return two;
}

void pre_order_traversal(Node *root)
{
    printf("%d  ", root->data);
    if (root->left != NULL)
    {
        pre_order_traversal(root->left);
    }

    if (root->right != NULL)
    {
        pre_order_traversal(root->right);
    }
}

void post_order_traversal(Node *root)
{
    if (root->left != NULL)
    {
        post_order_traversal(root->left);
    }

    if (root->right != NULL)
    {
        post_order_traversal(root->right);
    }

    printf("%d ", root->data);
}

int main()
{
    Node *root = create_tree();

    pre_order_traversal(root);
    printf("\n");
    post_order_traversal(root);

    return 0;
}