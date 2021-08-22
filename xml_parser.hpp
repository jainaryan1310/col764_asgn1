#ifndef XML_PARSER_HPP_INCLUDED
#define XML_PARSER_HPP_INCLUDED

#include <bits/stdc++.h>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class doc
{
private:
  string docno;
  string head;
  string text;

public:
  string doc_no() const
  {
    return docno;
  }

  string head() const
  {
    return head;
  }

  string text() const
  {
    return text;
  }

  doc(xml_node<> *node)
  {
    docno = node->first_node("DOCNO")->value();
    head = node->first_node("HEAD")->value();
    text = node->first_node("TEXT")->value();
  }
};

// doc *xml_parse(string file_name)
// {
//   ifstream t(file_name);
//   stringstream buffer;
//   buffer << t.rdbuf();

//   string text = buffer.str();
//   xml_document<> xml_d;
//   xml_d.parse<0>(&text[0]);
//   while (xml_d.first_node())
//   {

//   }
// }

#endif