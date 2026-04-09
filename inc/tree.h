/// ------------------------------------------
/// @file tree.h
///
/// @brief header file for binary tree structure
/// ------------------------------------------
#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/// @brief node in a tree structure, can be root or end node, stores an int
typedef struct
{
    // left or lesser node
    struct node *l_child;

    // right or greater child
    struct node *r_child;

    // data stored in node
    int data;
} node;

/// ------------------------------------------
/// @brief Initialses a tree with a pointer to the root node
/// Also can be used to free and reset an existing tree
/// To init nod should be a null ptr of type node
///
/// @param nod pointer to initialise
void init_node(node *nod);

/// ------------------------------------------
/// @brief Deletes given node and all downstream nodes
///
/// @param nod pointer to node to delete and all downstream
void prune_branch(node *nod);

/// ------------------------------------------
/// @brief Insert a data point into the tree structure, sorted by lesser/greater
///
/// @param root root of tree to insert into
/// @param data data to insert
void insert_data(node *root, int data);

/// ------------------------------------------
/// @brief Searches the tree for the first node with the search_data
/// returns NULL if data not found
///
/// @param root root of tree to search
/// @param search_data data to search for
///
/// @return ptr of first node to contain data, NULL if not found
node* find_node(node* root, int search_data);