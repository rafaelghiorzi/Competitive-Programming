#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> mapa(n);
    for (int i = 0; i < n; i++) {
        cin >> mapa[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mapa[i][j] != mapa[j][i]) {
                cout << "Nao" << endl;
                return 0;
            }
        }
    }

    cout << "Sim" << endl;

    return 0;
}
