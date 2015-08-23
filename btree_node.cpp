//
// Created by Santiago Castineira on 8/19/15.
//

#include "btree_node.h"
#include <iostream>

btree_node::btree_node() {
    // initialise to have one children per letter
    this->children = vector<btree_node *>(50, NULL);
}

void btree_node::add_word(string word)
{
    if (word.length() == 0){
        return;
    }

    int index = this->get_index_for_char(word[0]);

    if (this->children[index] == NULL){
        this->children[index] = new btree_node();
    }

    word = word.erase(0,1);

    this->children[index]->add_word(word);
}

bool btree_node::find(string word) {

    if (word.length() == 0){
        return true;
    }

    int index = this->get_index_for_char(word[0]);

    if (this->children[index] == NULL){
        return false;
    }

    word = word.erase(0,1);

    return this->children[index]->find(word);
}

int btree_node::get_index_for_char(char c){

    if ( c < 91 ){
        return c - 65;
    }else{
        return c - 97 + 25;
    }

}

char btree_node::get_char_for_index(int n) {
    if ( n < 25) {
        return (char)(n + 65);
    }else{
        return (char)(n - 25 + 97);
    }
}

int btree_node::print(int depth){

    int printed = 0;
    bool found = false;
    ++depth;
    for(int i = 0; i<this->children.size(); ++i){
        if (this->children[i] != NULL){

            if (found) {
                for (int i = 0; i < depth - 1 ; ++i) {
                    cout << " ";
                }
            }

            cout << this->get_char_for_index(i);

            found = true;
            printed++;

            if ( this->children[i]->print(depth) == 0 ){
                cout << endl;
            }

        }

    }

    return printed;
}


