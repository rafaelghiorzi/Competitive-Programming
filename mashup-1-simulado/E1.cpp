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
    
    vi lista(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }

    vi blocos;
    int contador = 1;

    for (int i = 1; i < n; i++) {
        if (lista[i] == lista[i -1]) {
            contador += 1;
        } else {
            blocos.push_back(contador);
            contador = 1;
        }
    }
    blocos.push_back(contador);

    int maximo = 0;
    for (int i = 1; i < blocos.size(); i++) {
        maximo = max(maximo, ( 2 * min(blocos[i - 1], blocos[i])));
    }

    cout << maximo << endl;

}

const bool TEST_CASES = 0;

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
