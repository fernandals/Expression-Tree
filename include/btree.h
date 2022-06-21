/*! 
 * @file btree.h
 * @brief Implementation of a binary tree.
 *
 * @author Fernanda Lustosa
 * @author Lucas Bazante
 */

#ifndef _BTREE_H_
#define _BTREE_H_

#include <stack>   // std::stack

struct node {
    char data = ' ';
    node *l = NULL;   // Pointer to left child
    node *r = NULL;  // Pointer to right child
};

class binary_tree {
    public:
        node *root;

        binary_tree();
        //~binary_tree();

        void insert( node*, std::stack< node >& );

    private:
        //std::stack< char > elements;   // Elements of the read expression

};

#endif
