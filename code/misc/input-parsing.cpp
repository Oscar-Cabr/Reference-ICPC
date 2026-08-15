#include <bits/stdc++.h>
using namespace std;

vector<string> splitLine() {
    string line;
    getline(cin, line);
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (ss >> token) tokens.push_back(token);
    return tokens;
}

/*
Usage example:
int main() {
    fastIO();
    int n; cin >> n;
    cin.ignore(); // ignore newline after reading n

    for (int i = 0; i < n; i++) {
        vector<string> line = splitLine();
        // process line...
    }
}
*/
