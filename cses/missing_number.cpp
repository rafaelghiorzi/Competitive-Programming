#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long res = ( n * (n + 1) / 2);
    long long sum;
    long long tmp;

    for (long long i = 0; i < n-1; i++) {
        cin >> tmp;
        sum += tmp;
    }

    cout << res - sum << endl;

    return 0;
}