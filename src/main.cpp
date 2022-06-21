/*!
 * @file main.cpp        
 *    
 * @author Fernanda Lustosa    
 * @author Lucas Bazante 
 */

//#include <iostream>
#include <fstream>   // std::ifstream | std::ofstream
#include <string>    // std::string
#include <stack>     // std::stack
#include <vector>    // std::vector
#include <sstream>   // std::istringstream

#include "../include/btree.h"
#include "../include/btree.inl"

int is_operator( const std::string value ){
    if( value == "+" or value == "-" or value == "*" or value == "/" )
        return 1;
    else
        return 0;
}

// Splits input string at the whitespaces 
void split_entry( const std::string &s, std::vector<std::string> *res ){
    std::istringstream iss(s);
    std::string item;
    while( std::getline(iss, item, ' ') )
        res->push_back(item);
}

int main(){
    std::ifstream file("../data/posfixa.in");
    std::ofstream out_inf("../data/infixa.out");
    std::ofstream out_pre("../data/prefixa.out");
    std::ofstream out_aval("../data/aval.out");
    std::string entry;
    
    if( file.is_open() ){
        while( std::getline( file, entry ) ){
            Binary_Tree bitree;
            std::stack< node* > elements;
          
            std::vector<std::string> values;
            split_entry(entry, &values);

            for( auto v : values ){
                node * nd = new node(v);

                // Operands are put into the stack while operators are send to 
                // the insert function to create their own tree
                if( is_operator(v) )
                    bitree.insert(nd, &elements);
                else
                    elements.push(nd);
            }

            bitree.pre_order(bitree.root, &out_pre);
            out_pre << std::endl;
            
            int res = bitree.post_order(bitree.root, &out_aval);
            out_aval << res << std::endl;
            
            bitree.inline_order(bitree.root, &out_inf);
            out_inf << std::endl;
        }    
    }

    out_pre.close();
    out_aval.close();
    out_inf.close();
    file.close();

    return 0;
}
