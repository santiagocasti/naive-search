#include "trie_node.h"
#include <iostream>

const int BTREE_SIZE = 25;
const int ASCII_NUM_A = 97;

/**
 * Constructor
 * Initialise the children vector to BTREE_SIZE places
 * since it supports only english alphabet in
 * ASCII representation.
 */
trie_node::trie_node() {
    // initialise to have one children per letter
    this->children = vector<trie_node *>(BTREE_SIZE, NULL);
}

/**
 * Adds a word to the b-tree.
 * The root node has BTREE_SIZE potential children, one for
 * each lowercasr letter in the english alphabet.
 *
 * One trie_node would be created per letter of the
 * word if there are not created yet (room for optimisation? yes!).
 */
void trie_node::add_term(string word)
{
    if (word.length() == 0){
        return;
    }

    this->to_lower_in_place(&word);

    int index = this->get_index_for_char(word[0]);

    if (this->children[index] == NULL){
        this->children[index] = new trie_node();
    }

    word = word.erase(0,1);

    this->children[index]->add_term(word);
}

/**
 * Find the given word in the btree.
 */
bool trie_node::find(string word) {

    if (word.length() == 0){
        return true;
    }

    this->to_lower_in_place(&word);

    int index = this->get_index_for_char(word[0]);

    if (this->children[index] == NULL){
        return false;
    }

    word = word.erase(0,1);

    return this->children[index]->find(word);
}

/**
 * Simple conversion from character to integer.
 * Used for indexing in the children array.
 */
int trie_node::get_index_for_char(char c){
        return c - ASCII_NUM_A;
}

/**
 * Simple conversion from integer to character.
 * Used for printing out the content of the btree.
 */
char trie_node::get_char_for_index(int n) {
    return (char)(n + ASCII_NUM_A);
}

/**
 * Convert a word to lowercase in place.
 */
void trie_node::to_lower_in_place(string *word) {
    transform(word->begin(), word->end(), word->begin(), ::tolower);
}

/**
 * Prints the words in the btree preorder.
 * It prints one word per line, when two words share some initial
 * characters, then those would be printed only once and
 * the second word would print spaces in the repeated characters.
 * Example with words fascinating, fashion and fast.
 * fascinating
 *    hion
 *    t
 */
int trie_node::print(int depth){

    int printed = 0;
    bool found = false;
    ++depth;
    for(int i = 0; i< this->children.size(); ++i){
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


