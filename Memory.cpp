#include "Memory.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void Memory :: load_instructions(string path) {

    ifstream inputfile(path);
      if (!inputfile.is_open()){
        cerr << "Failed to open the file\n";
        return;
    }
    
    string line;
    for (int it = 0; it < 256; it += 1){
        Memory_Cells[decimal_to_hexa(it)] = "00";
    }

    for (int it = 0; getline(inputfile, line); it += 2){
        ++number_of_inst;
        Memory_Cells[decimal_to_hexa(it)] = "";
        Memory_Cells[decimal_to_hexa(it)] += line[0];
        Memory_Cells[decimal_to_hexa(it)] += line[1];
        Memory_Cells[decimal_to_hexa(it + 1)] = "";
        Memory_Cells[decimal_to_hexa(it + 1)] += line[2];
        Memory_Cells[decimal_to_hexa(it + 1)] += line[3];
    }

    for (auto val : Memory_Cells){
        cout << val.first << ' ' << val.second << endl;
    }
    cout << number_of_inst << endl;
}

string Memory :: decimal_to_hexa(int dec){
    int x = dec / 16;
    string result = "";
    if (x <= 9){
        result += (char)x + 48;
    }
    else{
        x -= 10;
        result += (char)x + 65;
    }
    x = dec % 16;
    if (x <= 9){
        result += (char)x + 48;
    }
    else{
        x -= 10;
        result += (char)x + 65;
    }
    return result;
}