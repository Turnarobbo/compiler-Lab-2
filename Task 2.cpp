#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

bool isInteger(const string &token) {
    for (size_t i = 0; i < token.length(); ++i) {
        if (!isdigit(token[i]) && token[i] != '-' && token[i] != '+') {
            return false;
        }
    }
    return true;
}

bool isRealNumber(const string &token) {
    bool hasDecimalPoint = false;
    for (size_t i = 0; i < token.length(); ++i) {
        if (!isdigit(token[i])) {
            if (token[i] == '.' && !hasDecimalPoint) {
                hasDecimalPoint = true;
            } else {
                return false;
            }
        }
    }
    return hasDecimalPoint;
}

int main() {
    ifstream inputFile("program.txt");
    if (!inputFile.is_open()) {
        cerr << "Unable to open the input file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream tokenizer(line);
        string token;
        while (tokenizer >> token) {
            if (isInteger(token)) {
                cout << "Integer: " << token << endl;
            } else if (isRealNumber(token)) {
                cout << "Real Number: " << token << endl;
            }
        }
    }

    inputFile.close();
    return 0;
}
