#include <iostream>
#include <list>
#include "btree_node.h"
#include "inverted_index.h"

using namespace std;


void perform_search(btree_node* tree, string word){

    if (tree->find(word)){
        cout << "["+word+"] found!" << endl;
    }else{
        cout << "["+word+"] not found!" << endl;
    }

}

string reverse_word(string word){
    string reverse = string(word);

    for (int i = 0; i<word.length(); ++i){
        reverse[i] = word[word.length() -1 - i];
    }

    cout << "reversed word:" + reverse << endl;

    return reverse;
}

int main() {

    std::list<string> strings;
    strings.push_back("santiago");
    strings.push_back("agustin");
    strings.push_back("antonio");
    strings.push_back("anacleto");
    strings.push_back("anita");
    strings.push_back("ahora");

    btree_node* prefix_tree = new btree_node();
    btree_node* suffix_tree = new btree_node();


    for(std::list<string>::iterator stringListIterator = strings.begin(); stringListIterator != strings.end(); ++stringListIterator){
        prefix_tree->add_word(*stringListIterator);
        suffix_tree->add_word(reverse_word(*stringListIterator));
    }

    cout << "Printing prefix tree: " << endl;
    prefix_tree->print(0);

    cout << "Printing suffix tree: " << endl;
    suffix_tree->print(0);

    perform_search(prefix_tree, "antonio");

    inverted_index *index = new inverted_index();
    index->add("santiago", 57);
    index->add("santiago", 42);

    list<int>* doc_id_list = index->get_doc_ids("santiago");
    list<int>::iterator it = doc_id_list->begin();

    for(; it != doc_id_list->end(); ++it){
        cout << *it << endl;
    }



    return 0;
}