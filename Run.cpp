#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include "Memory.cpp"
using namespace std;

void binaryPrint(int n, string s = ""){
    if (n == 1){
        s = '1' + s;
        cout << s;
        return;
    }
    if (n == 0){
        cout << s;
        return;
    }

    s = to_string(n % 2) + s;
    return binaryPrint(n / 2, s);
}


int main() {
    Memory mem;
    mem.load_instructions("phishing.txt");
    


    return 0;
}
