#include "utils.h"
#include <cctype>
using namespace std;

string toLowerCase(string str) {
    for (char &c : str)
        c = tolower(c);
    return str;
}

string removeSpaces(string str) {
    string res = "";
    for (char c : str) {
        if (c != ' ')
            res += c;
    }
    return res;
}