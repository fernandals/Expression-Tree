/*! 
 * @file btree.h
 * @brief Implementation of a binary tree.
 *
 * @author Fernanda Lustosa
 * @author Lucas Bazante
 */

#ifndef _BTREE_H_
#define _BTREE_H_

#include <stack>    // std::stack
#include <fstream>  // std::ofstream
#include <string>   // std::stoi

struct node {
    std::string data;
    node *l = nullptr;   // Pointer to left child
    node *r = nullptr;   // Pointer to right child
    
    node(std::string str) {
        this->data = str;
        l = nullptr;
        r = nullptr;
    }
    node() {
        l = nullptr;
        r = nullptr;
    }
};

class Binary_Tree {
    public:
        node *root = nullptr;

        Binary_Tree();

        // Takes operators to create a tree for each and then merges the existing trees into one
        void insert( node*, std::stack< node* >* );
        // Creates input prefix format
        void pre_order( node*, std::ofstream* );
        // Evaluate the expression
        int post_order( node *, std::ofstream* );
        // Creates input inline format
        void inline_order( node *, std::ofstream* );

};

#endif
