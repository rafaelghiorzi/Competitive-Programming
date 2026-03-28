#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    unordered_map<int, int> cache(n);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cache[temp] = i;
    }

    int m;
    cin >> m;

    long long v = 0;
    long long p = 0;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        v += cache[x] + 1;
        p += n - cache[x];
    }

    cout << v << " " << p << endl;

    return 0;
}

