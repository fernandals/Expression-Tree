#include <iostream>
#include <fstream>
#include <string>

#include <stack>

#include "../include/btree.h"
#include "../include/btree.inl"

int is_operator( char value ){
    if( value == '+' or value == '-' or value == '*'
            or value == '/' or value == '^' )
        return 1;
    else
        return 0;
}

int main(){
    std::ifstream file("../data/posfixa.in");
    std::string entry;
    
    if( file.is_open() ){
        while( file ){
            std::getline( file, entry );
            std::cout << entry << std::endl;

            binary_tree *bitree = new binary_tree();
            std::stack< node > elements;
            
            for( auto e : entry ){
                if( e != ' ' ) {
                    node nd;
                    nd.data = e;
                    nd.l = NULL;
                    nd.r = NULL;

                    if( is_operator(e) ) {
                        bitree->insert(&nd, elements);

                        std::cout << "root " << bitree->root->data << std::endl;
                        std::cout << "left " << (bitree->root->l)->data << std::endl;
                        std::cout << "right " << (bitree->root->r)->data << std::endl;  
                    } else {
                        elements.push(nd);
                    }
                }
            }

        }    
    }



    file.close();

    return 0;
}
