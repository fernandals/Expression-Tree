/*!
 * @file btree.inl
 * @brief Implementation of the Binary Tree class methods.
 *
 * @author Fernanda Lustosa
 * @author Lucas Bazante
 */

#include "btree.h"

Binary_Tree::Binary_Tree() {
    root = NULL;
}

void Binary_Tree::insert( node *nd, std::stack< node* > *elements ){
    nd->r = elements->top();
    elements->pop();
 
    nd->l = elements->top();
    elements->pop();

    root = nd;

    elements->push(nd);
}

void Binary_Tree::pre_order(node *nd, std::ofstream *file) {
    *file << nd->data << " ";
    if (nd->l != nullptr)
        pre_order(nd->l, file);
    if (nd->r != nullptr)
        pre_order(nd->r, file);
}

int Binary_Tree::post_order(node *nd, std::ofstream *file) {
    if ( nd->l == nullptr && nd->r == nullptr )
        return std::stoi(nd->data);

    int x{}, y{};
    if (nd->l != nullptr)
        x = post_order(nd->l, file);
    if (nd->r != nullptr)
        y = post_order(nd->r, file);

    int res{};
    if (nd->data == "+")
        res = x + y;
    else if (nd->data == "-")
        res = x - y;
    else if (nd->data == "*")
        res = x * y;
    else
        res = x / y;

    return res;
}

void Binary_Tree::inline_order(node *nd, std::ofstream *file) {
    if (nd->l != nullptr)
        inline_order(nd->l, file);
    
    *file << nd->data << " ";
    
    if (nd->r != nullptr)
        inline_order(nd->r, file);
}
