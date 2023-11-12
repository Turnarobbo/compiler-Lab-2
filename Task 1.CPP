#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool isKeyword(const string &token) {
    string keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
        "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
        "union", "unsigned", "void", "volatile", "while"
    };

    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (token == keywords[i]) {
            return true;
        }
    }
    return false;
}

bool isOperator(const string &token) {
    string operators[] = {"+", "-", "*", "/", "=", "==", "!=", ">", "<", ">=", "<="};

    for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++) {
        if (token == operators[i]) {
            return true;
        }
    }
    return false;
}

bool isIdentifier(const string &token) {
    if (isalpha(token[0])) {
        for (int i = 0; i < token.size(); i++) {
            char c = token[i];
            if (!isalnum(c) && c != '_') {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    ifstream inputFile("program.txt");
    if (!inputFile.is_open()) {
        cerr << "Unable to open the input file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream tokenizer(line);
        string token;

        while (tokenizer >> token) {
            if (isKeyword(token)) {
                cout << "Keyword: " << token << endl;
            } else if (isOperator(token)) {
                cout << "Operator: " << token << endl;
            } else if (isIdentifier(token)) {
                cout << "Identifier: " << token << endl;
            } else {
                cout << "Unknown: " << token << endl;
            }
        }
    }

    inputFile.close();
    return 0;
}
