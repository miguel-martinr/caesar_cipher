#include "../include/caesar.hpp"

#include <sstream>
#include <cassert>

caesar::caesar(void) {

}

string caesar::str_toupper(string str) {
  string res;
  for (auto ch : str)
    res += toupper(ch);
  return res;
}

string caesar::str_tolower(string str) {
  string res;
  for (auto ch : str)
    res += tolower(ch);
  return res;
}


string caesar::encode(int offset, string str) {
  
  string res;
  for (auto ch : str) 
    res  +=  encode(offset, ch);
  
  return res;
}

string caesar::encode(int offset, char ch) {
  int alph_size = 26;
  int up_bound, low_bound;
  if(isupper(ch)) {
    up_bound = 90;
    low_bound = 65;
  } else {
    up_bound = 122;
    low_bound = 97;
  }
  
  if (int(ch) < low_bound || int(ch) > up_bound)
    return string() + ch;
  
  int a = int(ch) + offset - low_bound;
  int pos = (alph_size + (a % alph_size)) % alph_size;
  pos += low_bound;

  return (string() + char(pos));
}


string caesar::encode (string in_file, int offset) {
  ifstream input_s(in_file, ios::in);
  if (input_s) {
    ostringstream ss;
    ss << input_s.rdbuf();
    return encode(offset, ss.str());
  }
}

ostream& caesar::encode(int offset, istream& is, ostream& os) {
  string str;
  char ch;
  while (is.get(ch)) {
    str += ch;
  }
  os << encode(offset, str);
  return os;
}


