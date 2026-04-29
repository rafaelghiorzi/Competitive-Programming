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

ll gauss(ll a){ return a*(a+1)/2; }       // Sum 1 to a
ll teto(ll a, ll b){ return (a+b-1)/b; }  // rounded up division

// Prime numbers generator
const int MAXN = 1e5;
vector<int> primos;

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
    int n, c;
    cin >> n >> c;

    if (n == 2) {
        cout << 1 << endl;
        return;
    }

    vector<long long> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<long long> diff(n + 1, 0);

    for (int i = 0; i < c; i++) {
        int m;
        long long a;
        cin >> m >> a;

        diff[0] += a;
        diff[m] -= a;
    }

    long long cur = 0;
    for (int i = 0; i < n; i++) {
        cur += diff[i];
        h[i] += cur;
    }

    stack<long long> mono;
    mono.push(h[0]);

    for (int i = 1; i < n; i++) {        
        cout << mono.size() << endl;

        while (!mono.empty() && mono.top() <= h[i]) {
            mono.pop();
        }

        mono.push(h[i]);
    }
}

const bool TEST_CASES = 0;

int main(){
    // genprimos();

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    if (TEST_CASES) cin >> tc;

    while(tc--){
        solve();
    }

    return 0;
}
