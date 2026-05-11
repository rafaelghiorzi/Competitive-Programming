#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;

#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vll vector<long long>
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
    
    vector<vector<pll>> graph(n);
    for (int i = 0; i < m; i++) {
        int a,b,d;
        cin >> a >> b >> d;

        a--;
        b--;

        graph[a].pb(mkp(d, b));
        graph[b].pb(mkp(d, a));
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    
    const ll INF = 1e18;
    vll dist0(n, INF);
    vll distN(n, INF);

    dist0[0] = 0;
    distN[n-1] = 0;
    pq.push(mkp(0, 0));

    while(!pq.empty()) {
        pll top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if (d > dist0[u]) continue;

        for (pll p : graph[u]) {
            // explore all neighbours
            int w = p.first;
            int v = p.second;

            if (dist0[u] != INT_MAX && dist0[u] + w < dist0[v]) {
                dist0[v] = dist0[u] + w;
                pq.push(mkp(dist0[v], v));
            }
        }
    }

    pq.push(mkp(0, n-1));

    while(!pq.empty()) {
        pll top = pq.top();
        pq.pop();

        int d = top.first; // distance
        int u = top.second; // vertice

        if (d > distN[u]) continue;

        for (pll p : graph[u]) {
            // explore all neighbours
            int w = p.first;
            int v = p.second;

            if (distN[u] + w < distN[v]) {
                distN[v] = distN[u] + w;
                pq.push(mkp(distN[v], v));
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, dist0[i] + distN[i]);
    }

    cout << ans << endl;
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
