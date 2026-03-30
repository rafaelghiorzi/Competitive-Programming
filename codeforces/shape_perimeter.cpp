#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        
        int total_x = m;
        int total_y = m;

        int a,b;
        cin >> a >> b;

        for (int j = 0; j < n - 1; j++) {
            int x, y;
            cin >> x >> y;

            total_x += x;
            total_y += y;
        }

        int perimeter = 2*total_x + 2*total_y;

        cout << perimeter << endl;
    }
    
    return 0;
}
