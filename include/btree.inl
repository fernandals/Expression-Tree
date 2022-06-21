/*!
 * @file btree.inl
 * @brief Implementation of the Binary Tree class methods.
 *
 * @author Fernanda Lustosa
 * @author Lucas Bazante
 */

#include "btree.h"

binary_tree::binary_tree() {
    root = NULL;
}

void binary_tree::insert( node *nd, std::stack< node > &elements ){
    if( root == NULL ){
        root = nd;

        nd->l = &elements.top();
        elements.pop();

        nd->r = &elements.top();
        elements.pop(); 
        
        std::cout << "new root " << root->data << std::endl;
    } else {
        std::cout << "current root " << root->data << std::endl;
        
        nd->l = root;
        nd->r = &elements.top();
        elements.pop();

        root = nd;
    }


    /*
    //std::cout << "func root " << nd.data << std::endl;

    //nd->l = &elements.top();
    nd->l = root;
    //std::cout << "func left " << nd.l->data << std::endl;
    //elements.pop();
 
    nd->r = &elements.top();
    //std::cout << "func right " << nd.r->data << std::endl;
    elements.pop();

    root = nd;
    //std::cout << "func root 2 " << root->data << std::endl;
    //std::cout << "func left " << root->l->data << std::endl;
    //std::cout << "func right " << root->r->data << std::endl;

    //elements.push(*nd);
    */
}


