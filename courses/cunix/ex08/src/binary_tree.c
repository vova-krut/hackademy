#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  node {
  char          *key;
  void          *data;
  struct node   *left;
  struct node   *right;
}               node_t;

node_t *allocnode()
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node -> data = NULL;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}
node_t *insert(node_t *root, char *key, void *data)
{
    if (root != NULL)
    {
        if (root -> key >= key)
        {
            root -> right = insert(root -> right, key, data);
        }
        else
        {
            root -> left = insert(root -> left, key, data);
        }
    }
    root = allocnode();
    root -> key = key;
    root -> data = data;
    return root;
}
void print_node(node_t *node)
{
   node == NULL ? 0 : printf("%s\n", (char *) node -> data);
}
void visit_tree(node_t *node, void (*fp)(node_t *root))
{
    if (node != NULL)
    {
        visit_tree(node -> left, fp);
        visit_tree(node -> right, fp);
        fp(node);
    }
}
void destroy_tree(node_t *node, void (*fdestroy)(node_t *root))
{
    if (node != NULL)
    {
        destroy_tree(node -> left, fdestroy);
        destroy_tree(node -> right, fdestroy);
        fdestroy(node);
        free(node);
    }
}
