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

    vector<vector<pii>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;

        graph[a].pb(mkp(b, w));
        graph[b].pb(mkp(a, w));
    }

    const ll INF = 1e18;
    vector<ll> dist(n, INF);
    vi parent(n, -1);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[0] = 0;
    pq.push(mkp(0,0));

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(mkp(dist[v], v));
            }
        }

    }

    if (dist[n-1] == INF ) {
        cout << -1 << endl;
    } else {
        vi path;
        for (int v = n-1; v != -1; v = parent[v]) {
            path.pb(v);
        }
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) {
            cout << path[i] + 1 << " ";
        }
        cout << endl;

    }
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