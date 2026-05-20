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
    int n;
    cin >> n;
 
    vector<vi> board(n, vi(n, 0));
    vector<vi> graph(n*n);
 
    int x, y;
    cin >> x >> y;
    pii aq = {x, y};
    cin >> x >> y;
    pii bk = {x, y};
    cin >> x >> y;
    pii fc = {x, y};
 
    if (bk.first <= aq.first && fc.first >= aq.first) {
        cout << "NO" << endl;
        return;
    }
    if (bk.first >= aq.first && fc.first <= aq.first) {
        cout << "NO" << endl;
        return;
    }
    if (bk.second >= aq.second && fc.second <= aq.second) {
        cout << "NO" << endl;
        return;
    }
    if (bk.second >= aq.second && fc.second <= aq.second) {
        cout << "NO" << endl;
        return;
    }
    if (bk.second <= aq.second && fc.second >= aq.second) {
        cout << "NO" << endl;
        return;
    }
 
    cout << "YES" << endl;
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
