#include <bits/stdc++.h>
using namespace std;

int main() {

    int num;
    cin >> num;

    while (true) {
        num++;
        string seq = to_string(num);
        vector<bool> seen(10, false);
        bool ok = true;

        for (char c : seq) {
            if (seen[c - '0']) {
                ok = false;
                break;
            }
            seen[c - '0'] = true;
        }

        if (ok) {
            cout << num << endl;
            break;
        }
    }


    return 0;
}
