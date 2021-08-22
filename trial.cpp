#include <bits/stdc++.h>
// #include "porter_stemmer/porter_stemmer.hpp"
// #include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
// using namespace rapidxml;

int main()
{
  // string s = "playing";
  // char *p = &s[0];
  // int k;
  // s[stem(p, 0, s.length() - 1) + 1] = 0;
  // printf(&s[0]);

  string coll_path = "../tipster-ap-frac";
  for (const auto &file : filesystem::directory_iterator(coll_path))
  {
    cout << file.path() << endl;
  }
}