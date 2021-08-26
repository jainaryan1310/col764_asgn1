#ifndef INVERTED_INDEX_HPP_INCLUDED
#define INVERTED_INDEX_HPP_INCLUDED

#include <bits/stdc++.h>
#include "posting_list.hpp"

using namespace std;
using namespace rapidxml;

class inverted_index
{
private:
  long long num_terms;
  map<int, string> doc_id;
  map<string, posting_list> dictionary;

public:
  long long get_num_terms()
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

  void insert_doc_id(int docid, string docno)
  {
    doc_id[docid] = docno;
  }

  posting_list get_posting_list(string term)
  {
    if (dictionary.find(term) == dictionary.end())
    {
      posting_list npl = posting_list();
      return npl;
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
      posting_list p_list = dictionary[term];
      p_list.insert_doc(docid);
      dictionary[term] = p_list;
    }
    else
    {
      posting_list p_list = posting_list(term, docid);
      dictionary[term] = p_list;
      num_terms++;
    }
  }
};

#endif