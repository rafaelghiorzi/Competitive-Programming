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

ll ceil_log2(ll x) {
    ll p = 1;
    ll k = 0;

    while (p < x) {
        p <<= 1;
        k++;
    }

    return k;
}

ll g(ll r, ll c) {
    return ceil_log2(r) + ceil_log2(c);
}

void solve(){
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    ll rh = min(a, n - a + 1);
    ll cv = min(b, m - b + 1);

    ll ans = min( 1 + g(rh, m), 1 + g(cv, n) );

    cout << ans << endl;
}

const bool TEST_CASES = 1;

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
