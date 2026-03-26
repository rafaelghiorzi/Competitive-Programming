#include <bits/stdc++.h>
using namespace std;

int main() {

    string code;
    cin >> code;

    for (int i = 0; i < code.length(); i++) {
        if (code[i] == '.') {
            cout << '0';
            continue;
        }
        if (code[i + 1] == '.') {
            cout << '1';
            i++;
            continue;
        }
        if (code[i + 1] == '-') {
            cout << '2';
            i++;
            continue;
        }
    }

    return 0;
}