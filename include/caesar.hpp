#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;

class caesar {

 public:
   caesar(void);

   string encode(int offset, string str);
   string encode(int offset, char ch);
   string encode(string in_file, int offset);
   ostream& encode(int offset, istream& is, ostream& os = cout);
   string str_toupper(string str);
   string str_tolower(string str);


 private:

  
};