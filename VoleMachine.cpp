#include "VoleMachine.h"
#include <iostream>
string VoleMachine :: decimalToHexa(int dec){
    int x = dec / 16;
    string result;
    if (x <= 9) result += (char)(x + 48);
    else x -= 10, result += (char)(x + 65);

    x = dec % 16;

    if (x <= 9) result += (char)(x + 48);
    else x -= 10, result += (char)(x + 65);

    return result;
}

VoleMachine::VoleMachine() {
    counter = 0;
    instruction = "0000";
}

void VoleMachine::Fetch() {
    if(counter == machineMemory.number_of_instructions){
        instruction = "programm is endded to continue load another instruction:) ";
        return;
    }
    instruction = "";
    instruction += machineMemory.Memory_Cells[decimalToHexa(counter)];
    instruction += machineMemory.Memory_Cells[decimalToHexa(counter + 1)];
    counter += 2;
}

string VoleMachine:: Decode() {
    string decodedContent;
    if(instruction[0] == '1'){
        decodedContent = "LOAD the register ";
        decodedContent += instruction[1];
        decodedContent += " with the bit pattern found in the memory cell whose address is ";
        decodedContent += instruction[2];
        decodedContent += instruction[3];
    }

    if(instruction[0] == '2'){
        decodedContent = "LOAD the register ";
        decodedContent += instruction[1];
        decodedContent += " with the bit pattern ";
        decodedContent += instruction[2];
        decodedContent += instruction[3];
    }

    if(instruction[0] == '3'){
        decodedContent = "STORE the bit pattern found in register ";
        decodedContent += instruction[1];
        decodedContent += " in the memory cell whose address is ";
        decodedContent += instruction[2];
        decodedContent += instruction[3];
    }

    if(instruction[0] == '4'){
        decodedContent = "MOVE the bit pattern found in register ";
        decodedContent += instruction[2];
        decodedContent += " to register ";
        decodedContent += instruction[3];
    }

    if(instruction[0] == '5'){
        decodedContent = "ADD the bit patterns in registers ";
        decodedContent += instruction[2];
        decodedContent += " and ";
        decodedContent += instruction[3];
        decodedContent = "and leave the result in register ";
        decodedContent += instruction[1];
    }

    if(instruction[0] == 'B'){
        decodedContent = "JUMP to the instruction located in the memory cell at address ";
        decodedContent += instruction[2];
        decodedContent += instruction[3];
        decodedContent += " if the bit pattern in register ";
        decodedContent += instruction[1];
        decodedContent += " is equal to the bit pattern in register number 0";
    }

    if(instruction[0] == 'C'){
        decodedContent = "Halt execution";
    }

    return decodedContent;
}

void VoleMachine::Execute() {
    string memoryAddress;
    int addition{};
    char registerAddress, registerAddress2, registerAddress3;
    if(instruction[0] == '1'){
        memoryAddress += instruction[2], memoryAddress += instruction[3];
        registerAddress = instruction[1];
        machineRegister.Register_Cells[registerAddress] = machineMemory.Memory_Cells[memoryAddress];
    }

    else if(instruction[0] == '2'){
        registerAddress = instruction[1];
        machineRegister.Register_Cells[registerAddress] = "";
        machineRegister.Register_Cells[registerAddress] += instruction[2];
        machineRegister.Register_Cells[registerAddress] += instruction[3];
    }

    else if(instruction[0] == '3'){
        memoryAddress += instruction[2], memoryAddress += instruction[3];
        registerAddress = instruction[1];
        machineMemory.Memory_Cells[memoryAddress] = machineRegister.Register_Cells[registerAddress];
    }

    else if(instruction[0] == '4'){
        registerAddress = instruction[2];
        registerAddress2 = instruction[3];
        machineRegister.Register_Cells[registerAddress2] = machineRegister.Register_Cells[registerAddress];
    }

    if(instruction[0] == '5'){
        registerAddress = instruction[1];
        registerAddress2 = instruction[2];
        registerAddress3 = instruction[3];
        addition = hexaToDecimal(machineRegister.Register_Cells[registerAddress2]) + hexaToDecimal(machineRegister.Register_Cells[registerAddress3]);
        machineRegister.Register_Cells[registerAddress] = decimalToHexa(addition);
    }

    else if(instruction[0] == 'B'){
        memoryAddress += instruction[2], memoryAddress += instruction[3];
        counter = hexaToDecimal(memoryAddress);
        instruction = "";
        instruction += machineMemory.Memory_Cells[decimalToHexa(counter)];
        instruction += machineMemory.Memory_Cells[decimalToHexa(counter + 1)];
        counter += 2;
    }

    else if(instruction[0] == 'C'){
        cout << "Halt execution" << endl;
    }

    else cout << "invalid instruction" << endl;
}

int VoleMachine::hexaToDecimal(string hexa) {
    int result{0};
    if((int) hexa[0] >= 65 && (int) hexa[0] <= 90){
        result += ((int) hexa[0] - 55) * 16;
    }
    else result += ((int) hexa[0] - 48) * 16;

    if((int) hexa[1] >= 65 && (int) hexa[1] <= 90){
        result += (int) hexa[1] - 55;
    }
    else result += (int) hexa[1] - 48;
    return result;
}

void VoleMachine::runOneCycle() {
    Fetch();
    Decode();
    Execute();
}

