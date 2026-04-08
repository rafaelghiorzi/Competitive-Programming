#include <bits/stdc++.h>
#include <string>
using namespace std;
 
int main() {
    int vezes;
    cin >> vezes;
 
    for (int i = 0; i < vezes; i++) {
        string palavra;
        cin >> palavra;
 
        int tamanho = palavra.length();
 
        if (tamanho <= 10) {
            cout << palavra << endl;
        } else {
            int abreviar = tamanho - 2;
 
            cout << palavra[0] << abreviar << palavra[tamanho - 1] << endl;
        }
 
    }
    return 0;
}