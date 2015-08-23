//
// Created by Santiago Castineira on 8/20/15.
//

#include "inverted_index.h"

inverted_index::inverted_index(){
    this->index = new unordered_map<string, list<int>*>();
}

void inverted_index::add(string term, int doc_id){

    if (this->index->count(term) != 0){
        list<int> *doc_id_list = (list<int>*)this->index->at(term);
        doc_id_list->push_back(doc_id);
    }else{
        list<int> *doc_id_list = new list<int>();
        doc_id_list->push_back(doc_id);
        this->index->emplace(term, doc_id_list);
    }
}

list<int>* inverted_index::get_doc_ids(string term){

    list<int>* result;

    if (this->index->count(term) == 0){
        result = new list<int>();
    }else{
        result = this->index->at(term);
    }

    return result;
}