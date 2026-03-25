#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int fatorial = 5;
    int resultado = 0;

    while (fatorial <= n) {
        resultado += n / fatorial;
        fatorial *= 5;
    }

    cout << resultado;
    return 0;
}