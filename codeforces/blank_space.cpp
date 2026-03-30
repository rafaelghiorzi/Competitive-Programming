#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;


int main() {

    int t;
    cin >> t;   

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int sum = 0;
        int seq = 0;

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 0) {
                seq++;
            } else {
                sum = max(sum, seq);
                seq = 0; 
            }   
        }
        sum = max(sum, seq);
        cout << sum << endl;
    }

    return 0;
}
