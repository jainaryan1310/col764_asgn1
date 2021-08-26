#ifndef COMPRESSION_C2_HPP_INCLUDED
#define COMPRESSION_C2_HPP_INCLUDED

#include <bits/stdc++.h>
#include "posting_list.hpp"

vector<bitset<1>> U(int llx)
{
  vector<bitset<1>> v;
  v.push_back(0);
  llx--;
  while (llx > 0)
  {
    v.push_back(1);
    llx--;
  }
  return v;
}

int l(int x)
{
  return 1 + (int)(log2(x));
}

vector<bitset<1>> lsb(int a, int b)
{
  bitset<1> bit;
  vector<bitset<1>> res;
  while (b > 0)
  {
    bit = bitset<1>(a % 2);
    a = a / 2;
    res.push_back(bit);
    b--;
  }
  return res;
}

vector<bitset<1>> c2_compress(int docid)
{
  vector<bitset<1>> compressed_id;
  int lx = l(docid);
  int llx = l(lx);
  vector<bitset<1>> temp;
  temp = U(llx);
  while (temp.size() > 0)
  {
    compressed_id.push_back(temp.back());
    temp.pop_back();
  }
  temp = lsb(lx, llx - 1);
  while (temp.size() > 0)
  {
    compressed_id.push_back(temp.back());
    temp.pop_back();
  }
  temp = lsb(docid, lx - 1);
  while (temp.size() > 0)
  {
    compressed_id.push_back(temp.back());
    temp.pop_back();
  }
  return compressed_id;
}

vector<bitset<1>> c2_encode(posting_list p)
{
  long long size = p.get_size();
  vector<bitset<1>> compressed_list;
  vector<bitset<1>> compressed_id;
  for (long long i = 0; i < size; i++)
  {
    compressed_id = c2_compress(p.get_docid(i));
    for (auto it = compressed_id.begin(); it != compressed_id.end(); it++)
    {
      compressed_list.push_back(compressed_id[i]);
    }
  }
  return compressed_list;
}

int c2_decompress(vector<bitset<8>> compressed_id)
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

vector<int> c2_decode(vector<bitset<8>> compressed_list, long long size)
{
  vector<bitset<8>> compressed_id;
  bitset<8> b;
  int docid;
  for (long long i = 0; i < size; i++)
  {
    b = compressed_list[i];
    compressed_id.push_back(b);
    if (b[7] == 0)
    {
      docid = c2_decompress(compressed_id);
      compressed_id.clear();
    }
  }
}

#endif