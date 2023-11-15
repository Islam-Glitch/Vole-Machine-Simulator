// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifndef ___VOLEMACHINE_VOLEMACHINE_H
#define ___VOLEMACHINE_VOLEMACHINE_H
#include "Memory.h"
#include "Register.h"
class VoleMachine {
private:
    Memory machineMemory;
    Register machineRegister;
    int counter;
    string instruction;

public:
    VoleMachine();
    static string decimalToHexa(int dec);
    static int hexaToDecimal(string hexa);
    void Fetch();
    string Decode();
    void Execute();
    void runOneCycle();
    friend class VoleMachineGUI;
    string getMemoryContentAsString() const; // Add this line
    string getRegisterContentAsString() const; // Add this line
    string getDecodedContent() const;
};

#endif //___VOLEMACHINE_VOLEMACHINE_H
