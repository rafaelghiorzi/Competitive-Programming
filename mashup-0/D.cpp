#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count[5] = {0};

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        count[s]++;
    }

    int carros = 0;

    // para os grupos de quatro
    carros += count[4];

    // grupos de 3 compatíveis com grupos de 1
    carros += count[3];
    count[1] = max(0, count[1] - count[3]);

    // grupos de 2 cabe 2 em cada carro
    carros += count[2] / 2;
    // se for impar, sobra um carro
    if (count[2]  % 2 == 1) {
        carros++;
        // leva outros dois
        count[1] = max(0, count[1] - 2);
    }
    
    if (count[1] > 0) {
        carros += (count[1] + 3) / 4;
    }

    cout << carros << endl;

    return 0;    
}