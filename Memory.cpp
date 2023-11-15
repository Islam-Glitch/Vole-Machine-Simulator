#include "Memory.h"
#include <iostream>
#include <fstream>
using namespace std;

Memory::Memory() {
    for (int i{0}; i < 256; i++)
        Memory_Cells[decimalToHexa(i)] = "00";
}

void Memory :: load_instructions(const string& path) {
    string line;

    ifstream input(path);
    if (!input.is_open()){
        cout << "Failed to open the file\n";
        return;
    }


    for (int i{0}; getline(input, line); i += 2){
        number_of_instructions += 2;
        Memory_Cells[decimalToHexa(i)] = "";
        Memory_Cells[decimalToHexa(i)] += line[0];
        Memory_Cells[decimalToHexa(i)] += line[1];
        Memory_Cells[decimalToHexa(i + 1)] = "";
        Memory_Cells[decimalToHexa(i + 1)] += line[2];
        Memory_Cells[decimalToHexa(i + 1)] += line[3];
    }
}

string Memory :: decimalToHexa(const int& dec){
    int x = dec / 16;
    string result;
    if(x <= 9) result += (char)(x + 48);
    else x -= 10, result += (char)(x + 65);

    x = dec % 16;

    if (x <= 9) result += (char)(x + 48);
    else x -= 10, result += (char)(x + 65);

    return result;
}

void Memory::clearMemory() {
    number_of_instructions = 0;
    for (int i{0}; i < 256; i++)
        Memory_Cells[decimalToHexa(i)] = "00";
}


string Memory::getContentAsString() const {
    // Iterate through Memory_Cells and format the content as a string
    string content;
    for (const auto &pair : Memory_Cells) {
        content += pair.first + ": " + pair.second + "\n";
    }
    return content;
}
