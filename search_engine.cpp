#include <fstream>
#include <iostream>
#include "search_engine.h"

using namespace std;

search_engine::search_engine(){
    this->prefix_tree = new trie_node();
    this->suffix_tree = new trie_node();
    this->index= new inverted_index();
    this->document_list = new vector<pair<int, string>>();
}

/**
 * Indexes the terms appearing in the filename provided.
 */
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

/**
 * Indexes the terms appearing in the line provided,
 * associated to the document identifier provided.
 */
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
    return *this->index->get_doc_ids(term);
}

/**
 * Adds the document to the document list.
 */
int search_engine::add_document(string filename) {

    int doc_id = this->get_document_id(filename);

    if (doc_id == 0){
        doc_id = ++this->last_document_id;
        this->document_list->push_back(pair<int, string>(doc_id, filename));
    }

    return doc_id;
}

bool search_engine::has_indexed(string filename) {
    return (bool)this->get_document_id(filename);
}

/**
 * Returns the document ID of the filename provided.
 * Zero if it has not been indexed.
 */
int search_engine::get_document_id(string filename) {

    pair<int, string> *currentPair;

    for( int i = 0; i < this->document_list->size(); ++i){
        currentPair = &this->document_list->at(i);
        if (filename.compare(currentPair->second) == 0){
            return currentPair->first;
        }
    }

    return 0;
}

/**
 * Index the term associated to the document identifier provided.
 */
void search_engine::index_term(string term, int doc_id) {

    bool found = false;
    if (!this->prefix_tree->find(term)){
        this->prefix_tree->add_term(term);
    }

    if (!this->suffix_tree->find(term)){
        this->suffix_tree->add_term(term);
    }

    if (this->index->get_doc_ids(term)->size() == 0){
        this->index->add(term, doc_id);
    }

    cout <<  "[" + term + "] indexed"<< endl;
}

/**
 * Return the filepath of the document identified by docID, empty string otherwise.
 */
string search_engine::get_document_name(int docID) {

    for ( pair<int, string> document : *this->document_list ){
        if (document.first == docID){
            return document.second;
        }
    }

    // I strongly dislike this
    return "";
}