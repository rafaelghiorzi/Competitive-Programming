#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;


#define vi vector<int>
#define vll vector<ll>
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

void solve(){
    int n;
    cin >> n;


    vll piles(n);
    vll temps(n);
    for (int i = 0; i < n; i++) cin >> piles[i];
    for (int i = 0; i < n; i++) cin >> temps[i];

    vll psum(temps.size(), temps[0]);
    for (int i = 1; i < n; i++) psum[i] = temps[i] + psum[i-1];

    /*
    Pra cada pilha
    */

    vll delta(n+1, 0);
    vll extra(n, 0);

    for (int i = 0; i < n; i++) {
        ll prev (i == 0 ? 0 : psum[i-1]);
        ll alvo = piles[i] + prev;
        auto it = lower_bound(psum.begin(), psum.end(), alvo);
        ll k = it - psum.begin();
        
        delta[i] += 1;
        delta[k] -= 1;

        if (k <= n) {
            extra[k] += piles[i] - (psum[k-1] - prev);
        }
    }

    int ativos = 0;
    
    for (int i = 0; i < n; i++) {
        ativos += delta[i];
        cout << ativos * temps[i] + extra[i] << " ";
    } cout << endl;

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
