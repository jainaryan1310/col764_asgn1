#include <bits/stdc++.h>
#include "porter_stemmer/porter_stemmer.hpp"
// #include "rapidxml-1.13/rapidxml.hpp"
#include <ctype.h> /* for isupper, islower, tolower */

using namespace std;
// using namespace rapidxml;

int main()
{
  // string s = "playing";
  // char *p = &s[0];
  // p[stem(p, 0, s.length() - 1) + 1] = 0;
  // cout << p << endl;

  vector<string> a;
  a.push_back("aryan");
  a.push_back("jain");
  string p;
  for (auto it = a.begin(); it != a.end(); it++)
  {
    p.append(*it).append(" ");
  }
  cout << p << endl;
}