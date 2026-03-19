#include <bits/stdc++.h>
using namespace std;

int main() {
    int peso;
    cin >> peso;

    if ( ((peso-2) % 2 == 0) && ((peso-2) > 0) ) {
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl;
    }
}