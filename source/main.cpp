#include <iostream>
#include "../include/caesar.hpp" 


using namespace std;


int main(int argc, char* argv[]) {

  caesar coder;

  //Opcion 1: caesars OFFSET filein.txt fileout.txt
  if (argc == 4) {
    int offset = stoi(argv[1]);
    string in_name = argv[2], out_name = argv[3];
    ofstream file_out(out_name, ios::app);
    if (file_out) {
      file_out << coder.encode(in_name, offset) << endl;
    } else {
      cout << "Error al abrir " << out_name << " :( " << endl;
    }
  }
 return 0;
}