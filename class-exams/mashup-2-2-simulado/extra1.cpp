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
 
void solve(){
    int x, y, z;
    cin >> x >> y >> z;
 
    int m, n;
    cin >> m >> n;
 
    string wave;
    cin >> wave;
    queue<int> q;
 
    for (char c : wave) {
        if (c == 'F') {
            q.push(x);
        }
        if (c == 'A') {
            q.push(y);
        }
        if (c == 'R') {
            q.push(z);
        }
    }
 
    vi tamanduas = {m};
 
    while(!q.empty()) {
        int cupim = q.front(); q.pop();
 
        for (int i = 0; i < tamanduas.size(); i++) {
            if (cupim > tamanduas[i]) {
                continue;
            }
 
            tamanduas[i] -= cupim;
            cupim = 0;
        }
 
        if (cupim != 0) {
            tamanduas.push_back(m - cupim);
        }
    }
 
    cout << tamanduas.size() << endl;
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
