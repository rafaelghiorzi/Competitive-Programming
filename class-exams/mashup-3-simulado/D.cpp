#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;

#define vi vector<int>
#define vll vector<long long>
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
    // solve here
    int n, k;
    cin >> n >> k;

    vll v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<pair<ll, ll>> bits;
    ll ans = 0;

    for (int idx = 0; idx <= 30; idx++) {
        int custo = 0;

        for (int j = 0; j < n; j++) {
            // se for 0, adiciona ao custo
            if (!(v[j] & (1LL << idx))) {
                custo++;
            }
        }

        // se o custo é 0, nem adiciona, já soma em ans
        if (custo == 0) {
            ans += (1LL << idx);
            continue;

        }

        // adiciona no vetor o custo e o indice
        bits.pb({custo, idx});
    }

    // nao pode ser igual a n pq significa que nao tem nenhum numero
    // pega os maiores que o custo != n 
    // ve se cabe na quantidade de acoes
    // vai descendo
    reverse(bits.begin(), bits.end());

    for (int i = 0; i < bits.size(); i++) {        
        ll custo = bits[i].first;
        ll idx = bits[i].second;
        
        if (custo <= k) {
            k -= custo;
            ans += (1LL << idx);
        }
    }

    cout << ans << endl;

    // 2 1 1
    // 010 001 001

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
