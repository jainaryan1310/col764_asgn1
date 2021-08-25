#ifndef POSTING_LIST_HPP_INCLUDED
#define POSTING_LIST_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

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

#endif