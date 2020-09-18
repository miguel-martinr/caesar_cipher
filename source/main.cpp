#include "../include/caesar.hpp" 

#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {

  caesar coder;
  int offset;

  if (argc == 1) {
    cout << "MODOS DE USO:\n";
    cout << "caesar OFFSET file_in\n";
    cout << "caesar OFFSET file_in file_out\n\n";
    cout << "OFFSET:   numero entero\n";
    cout << "file_in:  fichero con texto a codificar\n";
    cout << "file_out: fichero donde se almacenará el texto codificado\n";
    cout << "\nNOTA: Si no se especifica un fichero de salida el programa usará la stdout\n";
  } else {

    offset = stoi(argv[1]);
    if (argc == 2) {
      //Todo: modo de entrada stdin
      coder.encode(offset, cin, cout);
      
    } else if (argc > 2) {

      string in_name = argv[2];
      string def_output;
      
      def_output = coder.encode(in_name, offset);
      

      if (argc == 3) {
        cout << def_output << endl;

      } else {
        string out_name;
        out_name = argv[3];
        ofstream file_out(out_name, ios::app);

        if (file_out) {
          file_out << def_output << endl;
        } else {
          cout << "Error al abrir " << out_name << endl;
        }
      }
    } else {
      cout << "MODOS DE USO:\n";
      cout << "caesar OFFSET file_in\n";
      cout << "caesar OFFSET file_in file_out\n\n";
      cout << "OFFSET:   numero entero\n";
      cout << "file_in:  fichero con texto a codificar\n";
      cout << "file_out: fichero donde se almacenará el texto codificado\n";
      cout << "\nNOTA: Si no se especifica un fichero de salida el programa usará la stdout\n";
    }
  }


 return 0;
}