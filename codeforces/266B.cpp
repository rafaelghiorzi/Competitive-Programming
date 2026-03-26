#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int x;
    cin >> n;
    cin >> x;
    string fila;
    cin >> fila;

    vector<char> lista(fila.begin(), fila.end());

    for (int i = 0; i < x; i++) {
        for (int j = lista.size() - 1; j > 0; j--) {
            if (lista[j - 1] == 'B' && lista[j] == 'G') { 
                swap(lista[j - 1], lista[j]);
                j--;
            }
        }
    }

    for (char c : lista) {
        cout << c;
    }

    return 0;
}
