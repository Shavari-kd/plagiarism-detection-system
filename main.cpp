#include <iostream>
#include <vector>
#include "lcs.h"
#include "similarity.h"
#include "utils.h"

using namespace std;

int main() {
    string text1, text2;

    // FIRST INPUT
    cout << "Enter first text:" << endl << endl;  // forces print
    getline(cin, text1);

    // SPACE BETWEEN INPUTS
    cout << endl << endl;  // 2 blank lines

    // SECOND INPUT
    cout << "Enter second text:" << endl << endl;
    getline(cin, text2);

    // PREPROCESSING
    text1 = toLowerCase(removeSpaces(text1));
    text2 = toLowerCase(removeSpaces(text2));


    vector<vector<int>> dp;

    // LCS CALCULATION
    int lcsLength = computeLCS(text1, text2, dp);
    string lcs = getLCS(text1, text2, dp);

    // SIMILARITY
    double similarity = calculateSimilarity(lcsLength, text1.length(), text2.length());

    // OUTPUT
    // OUTPUT
    cout << "\n----- RESULT -----\n\n\n";
    cout << "Text 1: " << text1 << endl << endl << endl;
    cout << "Text 2: " << text2 << endl << endl << endl;
    cout << "LCS: " << lcs << endl << endl << endl;
    cout << "LCS Length: " << lcsLength << endl << endl << endl;
    cout << "Similarity: " << similarity << "%" << endl << endl << endl;

    return 0;
}