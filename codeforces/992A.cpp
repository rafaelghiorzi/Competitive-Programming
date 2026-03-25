#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    set<int> lista;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp != 0) {
            lista.insert(temp);
        }
    }

    cout << lista.size() << endl;

    return 0;
}
