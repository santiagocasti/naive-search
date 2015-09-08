#include <iostream>
#include <list>
#include "trie_node.h"
#include "search_engine.h"

using namespace std;

/**
 * Show the menu that allows the user to index documents
 */
void handle_files_menu(search_engine *s) {
    system("clear");
    cout << "Naive Search Engine" << endl;
    cout << "Please introduce the full path of the file you would like to index:" << endl;

    char filepath[500];
    bool finished = false;

    while (!finished && cin.getline(filepath, 500)) {

        if (strcmp(filepath, "end") == 0){
            finished = true;
            continue;
        }

        s->index_document(filepath);
        string str(filepath);

        cout << "File [" + str + "] indexed" << endl;
        cout << "Any more? ['end' to finish]." << endl;
    }
}

/**
 * Show the menu that allows the user to search for terms
 */
void handle_search_menu(search_engine* s) {
    cout << "Introduce a term to search: " << endl;
    char word[20];
    bool finished = false;

    while (!finished && cin.getline(word, 20)) {
        if (strcmp(word, "end") == 0){
            finished = true;
            continue;
        }

        list<int> results = s->find(word);
        if (results.size() > 0) {
            cout << "Found in documents:" << endl;
            for (int docID : results) {
                cout << s->get_document_name(docID) + "," << endl;
            }
        }else{
            cout << "Term not found in any of the documents." << endl;
        }

        cout << "Any more? ['end' to finish]." << endl;
    }
}

int main(int argc, char** argv) {


//    /Users/santiago/code/naive-search/example.txt

    search_engine *s = new search_engine();

    handle_files_menu(s);

    handle_search_menu(s);

    return 0;
}