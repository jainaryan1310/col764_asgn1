#ifndef STRING_UTIL_HPP_INCLUDED
#define STRING_UTIL_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;

string trim(string s)
{
  return s.substr(s.find_first_not_of(" "), s.find_last_not_of(" ") - s.find_first_not_of(" ") + 1);
}

#endif