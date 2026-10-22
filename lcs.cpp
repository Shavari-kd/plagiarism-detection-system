#include "lcs.h"
#include <algorithm>
using namespace std;

int computeLCS(const string &X, const string &Y, vector<vector<int>> &dp) {
    int m = X.length(), n = Y.length();
    dp.assign(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

string getLCS(const string &X, const string &Y, vector<vector<int>> &dp) {
    int i = X.length(), j = Y.length();
    string lcs = "";

    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs = X[i-1] + lcs;
            i--; j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    return lcs;
}