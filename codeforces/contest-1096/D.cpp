#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;

#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mkp make_pair
#define endl '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

ll gauss(ll a){ return a*(a+1)/2; }
ll teto(ll a, ll b){ return (a+b-1)/b; }

const int MAXN = 1e5;
vi primos;

void genprimos(){
    vector<bool> is_prime(MAXN+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= MAXN; i++){
        if(is_prime[i]){
            primos.pb(i);
            for(int j = i*i; j <= MAXN; j += i){
                is_prime[j] = false;
            }
        }
    }
}


void solve() {
    int n;
    cin >> n;
    int len = 2 * n;
    vi a(len);
    for (int i = 0; i < len; i++) {
        cin >> a[i];
    }

    int max_mex = 0;
    vector<bool> seen(n + 1, false);

    for (int center = 0; center < 2 * len - 1; center++) {
        int left = center / 2;
        int right = (center + 1) / 2;

        while (left >= 0 && right < len && a[left] == a[right]) {
            left--;
            right++;
        }

        int l = left + 1;
        int r = right - 1;

        if (l <= r) {
            for (int i = l; i <= r; i++) {
                if (a[i] <= n) {
                    seen[a[i]] = true;
                }
            }
            int mex = 0;
            while (seen[mex]) {
                mex++;
            }

            max_mex = max(max_mex, mex);

            for (int i = l; i <= r; i++) {
                if (a[i] <= n) {
                    seen[a[i]] = false;
                }
            }
        }
    }
    cout << max_mex << endl;
}


const bool TEST_CASES = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    if (TEST_CASES) cin >> tc;

    while(tc--){
        solve();
    }

    return 0;
}
