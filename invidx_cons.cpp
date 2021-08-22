#include <bits/stdc++.h>
#include "porter_stemmer/porter_stemmer.hpp"
#include "rapidxml-1.13/rapidxml.hpp"
#include "inverted_index.hpp"

using namespace std;
using namespace rapidxml;

int main()
{
  string coll_path = "../tipster-ap-frac";
  string indexfile;
  int compression;
  vector<string> xml_tags_info;
  vector<string> stop_words;
  xml_document<> xml_d;
  inverted_index ii;

  for (const auto &file : filesystem::directory_iterator(coll_path))
  {
    ifstream t(file.path());
    stringstream buffer;
    buffer << t.rdbuf();
    string text = buffer.str();
    xml_d.clear();
    xml_d.parse<0>(&text[0]);
    int docid = 0;
    string s;
    stringstream ss;
    string docno;

    while (xml_d.first_node())
    {
      docno = xml_d.first_node()->first_node("DOCNO")->value();
      for (auto it = xml_tags_info.begin(); it != xml_tags_info.end(); it++)
      {
        string tag = *it;
        ss << xml_d.first_node()->first_node(tag.c_str())->value();
      }
    }
  }
}