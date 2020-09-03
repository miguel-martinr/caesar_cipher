#include <string>
#include <vector>
#include <cctype>
#include <fstream>

using namespace std;

class caesar {

 public:
   caesar(void);

   string encode(int offset, string str);
   string encode (int offset, char ch);
   string encode (string in_file, int offset);
   string str_toupper(string str);

 private:

  
};