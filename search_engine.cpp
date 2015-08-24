#include <fstream>
#include <iostream>
#include "search_engine.h"

using namespace std;

void search_engine::index_document(string filename) {

    int doc_id = this->get_document_id(filename);

    if (doc_id != 0){
        // file already indexed
        return;
    }

    doc_id = this->add_document(filename);

    string line;
    ifstream fileReference (filename);

    if (fileReference.is_open()) {
        while (getline(fileReference, line)) {
            this->index_line(line, doc_id);
        }
        fileReference.close();
    }

}

void search_engine::index_line(string line, int doc_id) {

    int start = 0;
    string term;
    for (int i = 0; i <= line.length(); ++i) {

        if (line[i] == ' ' || i == line.length()) {

            if (start < i) {
                term = line.substr(start, i - start);
                this->index_term(term, doc_id);
            }

            start = i + 1;
        }
    }
}

list<int> search_engine::find(string term) {

}

int search_engine::add_document(string filename) {

    int doc_id = this->get_document_id(filename);

    if (doc_id != 0){
        doc_id = ++this->last_document_id;
        this->document_list->push_back(pair<int, string>(doc_id, filename));
    }

    return doc_id;
}

bool search_engine::has_indexed(string filename) {
    return (bool)this->get_document_id(filename);
}

int search_engine::get_document_id(string filename) {

    for( list<pair<int, string>>::iterator it = this->document_list->begin(); it != this->document_list->end(); it++){
        if (filename.compare(it->second) == 0){
            return it->first;
        }
    }

    return 0;
}

void search_engine::index_term(string term, int doc_id) {
    this->prefix_tree->add_term(term);
    this->suffix_tree->add_term(term);
    this->index->add(term, doc_id);
    cout <<  "[" + term + "] indexed"<< endl;
}