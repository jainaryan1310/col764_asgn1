#include <bits/stdc++.h>
#include "porter_stemmer/porter_stemmer.hpp"
#include "rapidxml-1.13/rapidxml.hpp"
#include "inverted_index.hpp"
#include "string_util.hpp"

using namespace std;
using namespace rapidxml;

int main()
{
  string coll_path = "./sample2";
  string indexfile;
  int compression;
  vector<string> xml_tags_info;
  vector<string> stop_words;
  unordered_set<string> stopwords;
  for (vector<string>::iterator it = stop_words.begin(); it != stop_words.end(); it++)
  {
    stopwords.insert(*it);
  }
  xml_document<> xml_d;
  inverted_index ii;
  regex re(R"([\s|,|.|:|;|"|'|_|-|\{|\}|\[|\]|\n|`|\(|\)]+)");
  int docid = 0;
  xml_tags_info.push_back("HEAD");
  xml_tags_info.push_back("TEXT");

  for (const auto &file : filesystem::directory_iterator(coll_path))
  {
    ifstream t(file.path());
    stringstream buffer;
    buffer << t.rdbuf();
    string file_text = buffer.str();
    xml_d.clear();
    xml_d.parse<0>(&file_text[0]);
    string s;
    string text = "";
    string docno;
    string stemmed_text;
    char *p;

    while (xml_d.first_node())
    {
      text = "";
      docno = xml_d.first_node()->first_node("DOCNO")->value();
      docno = trim(docno);
      ii.insert_doc_id(docid, docno);

      for (auto it = xml_tags_info.begin(); it != xml_tags_info.end(); it++)
      {
        string tag = *it;
        if (xml_d.first_node()->first_node(tag.c_str()))
        {
          text.append(xml_d.first_node()->first_node(tag.c_str())->value()).append(" ");
        }
      }

      sregex_token_iterator it_begin = sregex_token_iterator(text.begin(), text.end(), re, -1);
      sregex_token_iterator it_end = sregex_token_iterator();
      for (sregex_token_iterator it = it_begin; it != it_end; it++)
      {
        if (*it == "" || stopwords.find(*it) != stopwords.end())
        {
          continue;
        }

        s = *it;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        p = &s[0];
        p[stem(p, 0, s.length() - 1) + 1] = 0;
        s = p;
        ii.insert(s, docid);
      }
      xml_d.remove_first_node();
      docid++;
    }
  }
  posting_list p = ii.get_posting_list("the");
  p.print_list();
}