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
    int n, m;
    cin >> n >> m;

    vector<vi> graph(n);
    vi backtrack(n, -1);

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start = 0;
    backtrack[start] = start;
    
    vector<bool> visited(n, false);
    visited[start] = true;

    queue<int> q;
    q.push(start);
    
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                backtrack[v] = u;
            }
        }
    }

    int end = n - 1;
    if (!visited[end]) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vi ans;
    int curr = end;
    while (curr != start) {
        ans.push_back(curr);
        curr = backtrack[curr];
    }
    ans.push_back(start);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int a : ans) {
        cout << a + 1 << " ";
    }
    cout << endl;
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
