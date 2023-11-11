#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
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


// void stoin(){

// }

// void Hexa_Bin(string s){
//     for(int i = 0; i < s.size(); ++i){
//         if(stoi("5"));

//     }
    
// }

void readfile(string path) {

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

int main() {
    string s; cin >> s;
    readfile(s);


    return 0;
}
