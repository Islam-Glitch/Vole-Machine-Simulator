#include "Instructions.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void Instructions :: readfile(string path) {

    ifstream inputfile(path);
      if (!inputfile.is_open()){
        cerr << "Failed to open the file\n";
        return;
    }

    string line;
    while (getline(inputfile, line)){
        cout << line << endl;
    }
}