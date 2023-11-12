// BigReal.h
#ifndef VoleMachine_H
#define VoleMachine_H

#include <iostream>
#include <string>
#include <map>
using namespace std;




class Memory {
private:
    map <string, string> Memory_Cells;
    int number_of_inst{};

public:
    friend class VoleMachine;
    void load_instructions(string path);
    string decimal_to_hexa(int dec);

};

#endif
