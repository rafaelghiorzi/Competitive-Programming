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


vector<set<int>> graph;
vector<bool> visited;

bool dfs(int u, int parent) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v]) {
            if (dfs(v, u)) {
                return true;
            }
        } else if ( v != parent ) {
            return true;
        }
    }

    return false;
}

void solve(){
    int n;
    cin >> n;
    
    graph.assign(n, {});
    visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        v--;

        graph[i].insert(v); 
        graph[v].insert(i);
    }

    int cycles = 0;
    int non_cycles = 0;

    // use dfs
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        if (dfs(i, -1)) {
            cycles++;
        } else {
            non_cycles++;
        }
    }
    

    int max_dances = cycles + non_cycles;
    int min_dances = cycles + (non_cycles > 0 ? 1 : 0);

    cout << min_dances << " " << max_dances << endl;
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
