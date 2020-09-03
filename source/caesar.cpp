#include "../include/caesar.hpp"

#include <sstream>

caesar::caesar(void) {

}

string caesar::str_toupper(string str) {
  string res;
  for (auto ch : str)
    res += toupper(ch);
  return res;
}

string caesar::encode(int offset, string str) {
  
  str = str_toupper(str);
  string res;
  for (auto ch : str) 
    res  +=  encode(offset, ch);
  
  return res;
}

string caesar::encode(int offset, char ch) {
  int alph_size = 26;

  
  if (int(ch) < 65 || int(ch) > 90)
    return string() + ch;
  
  int a = int(ch) + offset - 65;
  int pos = (alph_size + (a % alph_size)) % alph_size;
  pos += 65;

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