#ifndef WILDCARDSEARCH_BTREE_H
#define WILDCARDSEARCH_BTREE_H

#include <string>
#include <vector>

using namespace std;

class trie_node {
    vector <trie_node *> children;
public:
    trie_node();
    bool find(string);
    void add_term(string);
    int print(int);
private:
    int get_index_for_char(char);
    char get_char_for_index(int);
    void to_lower_in_place(string*);
};

#endif //WILDCARDSEARCH_BTREE_H
