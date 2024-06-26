// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifndef ___VOLEMACHINE_REGISTER_H
#define ___VOLEMACHINE_REGISTER_H
#include <string>
#include <map>
using namespace std;

class Register{
private:
    map <char, string> Register_Cells;

public:
    Register();
    static char decimalToHexa(int dec);
    void clearRegister();
    friend class VoleMachine;
    friend class MainWindow;
    string getState() const;
    string getContentAsString() const;
};

#endif //___VOLEMACHINE_REGISTER_H
