#ifndef COMPRESSION_C1_HPP_INCLUDED
#define COMPRESSION_C1_HPP_INCLUDED

#include <bits/stdc++.h>
#include "posting_list.hpp"

vector<bitset<8>> c1_compress(int docid)
{
  vector<bitset<8>> v;
  bitset<8> b(docid % 128);
  docid = docid / 128;
  v.push_back(b);

  while (docid > 0)
  {
    b = bitset<8>(docid % 128);
    b[7] = 1;
    docid = docid / 128;
    v.push_back(b);
  }

  return v;
}

vector<bitset<8>> c1_encode(posting_list p)
{
  long long size = p.get_size();
  vector<bitset<8>> compressed_list;
  vector<bitset<8>> compressed_id;
  for (long long i = 0; i < size; i++)
  {
    compressed_id = c1_compress(p.get_docid(i));
    while (compressed_id.size() > 0)
    {
      compressed_list.push_back(compressed_id.back());
      compressed_id.pop_back();
    }
  }
  return compressed_list;
}

int c1_decompress(vector<bitset<8>> compressed_id)
{
  bitset<8> b = compressed_id[0];
  b[7] = 0;
  int docid = (int)(b.to_ulong());

  for (int i = 1; i < compressed_id.size(); i++)
  {
    docid = docid * 128;
    b = compressed_id[i];
    b[7] = 0;
    docid += (int)(b.to_ulong());
  }
  return docid;
}

vector<int> c1_decode(vector<bitset<8>> compressed_list, long long size)
{
  vector<bitset<8>> compressed_id;
  bitset<8> b;
  int docid;
  vector<int> docid_list;
  for (long long i = 0; i < size; i++)
  {
    b = compressed_list[i];
    compressed_id.push_back(b);
    if (b[7] == 0)
    {
      docid = c1_decompress(compressed_id);
      compressed_id.clear();
      docid_list.push_back(docid);
    }
  }
  return docid_list;
}

#endif