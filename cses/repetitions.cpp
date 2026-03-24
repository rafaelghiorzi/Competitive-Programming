#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    char atual = s[0];
    int seq = 1;
    int sum = 1;

    for (size_t i = 1; i < s.length(); i++) {
        if (s[i] == atual) {
            sum++;
        } else {
            seq = max(seq, sum);
            atual = s[i];
            sum = 1;
        }
    }

    seq = max(seq, sum);
    cout << seq << endl;

    return 0;
}