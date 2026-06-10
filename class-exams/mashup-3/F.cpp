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

/*
the sum of the elements at even indices 
(with respect to the original array) is greater 
than or equal to the sum of the elements at odd indices.
*/

void solve(){
    ll n;
    cin >> n;

    ll ops = 0;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i += 2) {
        ll left = a[i-1];
        ll right = i < n - 1 ? a[i+1] : 0;
        ll curr = a[i];

        if (curr >= (left + right)) continue;

        ll diff = abs(curr - (left + right));
        ops += diff;

        if (right < diff) {
            right = 0;
            left -= diff - right;
        } else {
            right -= diff;
        }

        a[i-1] = left;
        if (i + 1 < n) a[i+1] = right;
    }

    cout << ops << endl;
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
