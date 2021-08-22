#ifndef INVERTED_INDEX_HPP_INCLUDED
#define INVERTED_INDEX_HPP_INCLUDED

#include <bits/stdc++.h>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class posting_list
{
private:
  string term_idx;
  vector<int> list;

public:
  posting_list(string term, int docid)
  {
    term_idx = term;
    list.clear();
    list.push_back(docid);
  }

  void insert_doc(int docid)
  {
    list.push_back(docid);
  }
};

class inverted_index
{
private:
  int num_terms;
  map<int, string> doc_id;
  map<string, posting_list *> dictionary;

public:
  int num_terms()
  {
    return num_terms;
  }

  string get_docno(int docid)
  {
    if (doc_id.find(docid) != doc_id.end())
    {
      return doc_id[docid];
    }
    else
    {
      return "";
    }
  }

  int get_docid(string docno)
  {
    map<int, string>::iterator it;
    for (it = doc_id.begin(); it != doc_id.end(); it++)
    {
      if (get<1>(*it) == docno)
      {
        break;
      }
    }
    if (it == doc_id.end())
    {
      return -1;
    }
    else
    {
      return get<0>(*it);
    }
  }

  posting_list *get_posting_list(string term)
  {
    if (dictionary.find(term) == dictionary.end())
    {
      posting_list *null_posting_list;
      return null_posting_list;
    }
    else
    {
      return dictionary[term];
    }
  }

  void insert(string term, int docid)
  {
    if (dictionary.find(term) != dictionary.end())
    {
      posting_list *p_list = get_posting_list(term);
      p_list->insert_doc(docid);
    }
    else
    {
      posting_list p_list(term, docid);
      dictionary[term] = &p_list;
      num_terms++;
    }
  }
};

#endif