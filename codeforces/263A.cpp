#include <bits/stdc++.h>
using namespace std;

int main() {

    int x = 0;
    int y = 0;
    int find = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> find;
            if (find == 1) {
                x = j;
                y = i;
                break;
            }
        }
        if (find == 1) {
            break;
        }
    }

    x = abs(x - 2);
    y = abs(y - 2);
    int moves = x + y;

    cout << moves << endl;


    return 0;
}
