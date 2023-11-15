#include "Register.h"

char Register :: decimalToHexa(int dec){
    char result;
    if (dec <= 9) result = (char)(dec + 48);
    else dec -= 10, result = (char)(dec + 65);

    return result;
}

Register::Register(){
    for (int i{0}; i < 16; i++)
        Register_Cells[decimalToHexa(i)] = "00";
}

void Register::clearRegister() {
    for (int i{0}; i < 16; i++)
        Register_Cells[decimalToHexa(i)] = "00";
}


string Register::getContentAsString() const {
    // Iterate through Register_Cells and format the content as a string
    string content;
    for (const auto &pair : Register_Cells) {
        content += pair.first;
        content += ": ";
        content += pair.second;
        content += "\n";
    }
    return content;
}
