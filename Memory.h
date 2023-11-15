// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifndef ___VOLEMACHINE_MEMORY_H
#define ___VOLEMACHINE_MEMORY_H
#include <string>
#include <map>
using namespace std;

class Memory {
private:
    map <string, string> Memory_Cells;
    int number_of_instructions{};

public:
    Memory();
    void load_instructions(const string& path);
    static string decimalToHexa(const int& dec);
    void clearMemory();
    friend class VoleMachine;
    friend class MainWindow;
    string getState() const;  // Add this method
    int getInstructionCount() const;
    string getContentAsString() const;
};

#endif //___VOLEMACHINE_MEMORY_H
