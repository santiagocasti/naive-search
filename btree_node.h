//
// Created by Santiago Castineira on 8/19/15.
//

#ifndef WILDCARDSEARCH_BTREE_H
#define WILDCARDSEARCH_BTREE_H

#include <string>
#include <vector>

using namespace std;

class btree_node {
    vector <btree_node *> children;
public:
    btree_node();
//    btree_node parent();
//    btree_node* get_children();
    bool find(string);
    void add_word(string);
//    void remove_children(btree_node* node);
    int print(int);
private:
    int get_index_for_char(char c);
    char get_char_for_index(int n);
};


#endif //WILDCARDSEARCH_BTREE_H
