#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> lista;

    int vezes;
    cin >> vezes;

    for (int i = 0; i < vezes; i++) {
        string nome;
        cin >> nome;
        
        if (!lista.count(nome)) {
            cout << "OK" << endl;
            lista[nome] = 1;
        } else {
            string candidato = nome + to_string(lista[nome]);
            lista[nome] += 1;
            cout << candidato << endl;
        }
    }
}
