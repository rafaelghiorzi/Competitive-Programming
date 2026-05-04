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
    string palavra;
    cin >> palavra;
    vi al(26, 0);

    for (int i = 0; i < palavra.size(); i++) {
        al[palavra[i] - 'a']++;
    }

    int gap = 0;
    bool flag = false;

    for (int i = 0; i < al.size(); i++) {
        if (al[i] > 1) {
            cout << "No" << endl;
            return;
        }

        if (al[i] == 1 && !flag) {
            flag = true;
            gap++;
        } else if (al[i] == 0) {
            flag = false;
        }
    }

    if (gap > 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
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
