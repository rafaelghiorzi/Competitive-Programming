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
    vi rel(12, 0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    rel[a-1] = 1;
    rel[b-1] = 1;
    rel[c-1] = 2;
    rel[d-1] = 2;

    int tmp = 0;
    for (int n : rel) {
        if (n != 0) {
            if (n == tmp) {
                cout << "NO" << endl;
                return;
            } else {
                tmp = n;
            }
        }
    }

    cout << "YES" << endl;

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
