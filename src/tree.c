#include "../inc/tree.h"

/// ------------------------------------------
void init_node(node *nod, int root_data)
{
    if (nod != NULL)
    {
        prune_branch(nod);
    }

    nod = malloc(sizeof(node));

    nod->l_child = NULL;
    nod->r_child = NULL;
    nod->data = root_data;
}

/// ------------------------------------------
void prune_branch(node *nod)
{
    if (nod->l_child != NULL)
    {
        prune_branch(nod->l_child);
    }

    if (nod->r_child != NULL)
    {
        prune_branch(nod->r_child);
    }

    free(nod);
}

/// ------------------------------------------
void insert_data(node *root, int data)
{
    if (data < root->data)
    {
        if (root->l_child != NULL)
        {
            insert_data(root->l_child, data);
        }
        else
        {
            init_node(root->l_child, data);
        }
    }
    else
    {
        if (root->r_child != NULL)
        {
            insert_data(root->r_child, data);
        }
        else
        {
            init_node(root->r_child, data);
        }
    }
}

/// ------------------------------------------
node* find_node(node* root, int search_data)
{
    // depth first search
    if (root == NULL) return NULL;

    if (root->data == search_data)
    {
        return root;
    }
    else
    {
        node* res = find_node(root->l_child, search_data);
        if (res != NULL) return res;

        res = find_node(root->r_child, search_data);
        return res;
    }
}