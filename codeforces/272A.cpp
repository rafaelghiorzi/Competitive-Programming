#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; // not couting Dima
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    
    n += 1; // add Dima 

    cout << endl;

    int dima = 0;
    for (int i = 1; i <= 5; i++) {

        if ((sum + i) % n != 1) {
            dima++;
        }
    }

    cout << endl;
    cout << dima << endl;


    return 0;
}
