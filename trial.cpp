#include <bits/stdc++.h>
#include "porter_stemmer/porter_stemmer.hpp"
#include "rapidxml-1.13/rapidxml.hpp"
#include <ctype.h> /* for isupper, islower, tolower */

using namespace std;
using namespace rapidxml;

int main()
{
  // string s;
  // cin >> s;
  // char *p = &s[0];
  // p[stem(p, 0, s.length() - 1) + 1] = 0;
  // string k = p;
  // cout << k << endl;

  // vector<string> a;
  // a.push_back("aryan");
  // a.push_back("jain");
  // string p;
  // for (auto it = a.begin(); it != a.end(); it++)
  // {
  //   p.append(*it).append(" ");
  // }
  // cout << p << endl;

  // ifstream t("./f1");
  // stringstream buffer;
  // buffer << t.rdbuf();
  // string text = buffer.str();
  // regex re(R"([\s|,|.|:|;|"|'|\{|\}|\[|\]|\n|`|\(|\)]+)");
  // sregex_token_iterator it_begin = sregex_token_iterator(text.begin(), text.end(), re, -1);
  // sregex_token_iterator it_end = sregex_token_iterator();

  // for (sregex_token_iterator it = it_begin; it != it_end; it++)
  // {
  //   if (*it != "")
  //   {
  //     cout << *it << endl;
  //   }
  // }

  xml_document<> xml_d;
  string path = "../tipster-ap-frac";
  int docid = 0;
  for (const auto &file : filesystem::directory_iterator(path))
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
      cout << docid << endl;
      docid++;
      xml_d.remove_first_node();
    }
  }
}