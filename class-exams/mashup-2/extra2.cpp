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

    // pode exisitir o edge case de só ter 

    vector<vector<int>> graph(n);
    vi roots;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == -1) {
            roots.push_back(i);
            continue;
        }

        tmp--;
        graph[tmp].push_back(i);
    }

    int max_depth = 0;

    for (int root : roots) {
        stack<pii> s;
        s.push({root, 1});

        while (!s.empty()) {
            auto [node, c_depth] = s.top(); s.pop();
            max_depth = max(max_depth, c_depth);

            for (int v : graph[node]) {
                s.push({v, c_depth + 1});
            }
        }
    }

    cout << max_depth << endl;
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
