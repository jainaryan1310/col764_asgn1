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
  int *list;
  long long size = 0;

public:
  posting_list()
  {
    size = 0;
  }

  posting_list(string term, int docid)
  {
    term_idx = term;
    size = 1;
    int *new_list = new int[size];
    new_list[0] = docid;
    list = new_list;
  }

  long long get_size()
  {
    return size;
  }

  void print_list()
  {
    for (long long i = 0; i < size - 1; i++)
    {
      cout << list[i] << ", ";
    }
    cout << list[size - 1] << endl;
  }

  void insert_doc(int docid)
  {
    if (size >= sizeof(list) / sizeof(list[0]))
    {
      int *new_list = new int[size * 2];
      for (long long i = 0; i < size; i++)
      {
        new_list[i] = list[i];
      }
      list = new_list;
    }
    list[size] = docid - list[size - 1];
    size++;
  }
};

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