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

    pii start;
    pii end;

    vector<vector<vector<pii>>> graph(n, vector<vector<pii>>(m));
    vector<vector<pii>> backtrack(n, vector<pii>(m, {-1,-1}));
    backtrack[start.first][start.second] = start;
    vector<string> grid(n);

    for (int i = 0; i < n; i++) cin >> grid[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') continue;
            if (grid[i][j] == 'A') start = {i,j};
            if (grid[i][j] == 'B') end = {i,j};

            if (i > 0 && grid[i-1][j] != '#')
                graph[i][j].push_back({i-1, j});
            if (i+1 < n && grid[i+1][j] != '#')
                graph[i][j].push_back({i+1, j});
            if (j > 0 && grid[i][j-1] != '#')
                graph[i][j].push_back({i, j-1});
            if (j+1 < m && grid[i][j+1] != '#')
                graph[i][j].push_back({i, j+1});

        }
    }

    queue<pii> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    q.push(start);
    visited[start.first][start.second] = true;

    while (q.size()) {
        pii u = q.front();
        q.pop();

        for (pii v : graph[u.first][u.second]) {
            if (!visited[v.first][v.second]) {
                q.push(v);
                visited[v.first][v.second] = true;
                backtrack[v.first][v.second] = u;
            }
        }
    }

    if (!visited[end.first][end.second]) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<pii> ans;
    pii curr = end;
    while (curr != start) {
        ans.push_back(curr);
        curr = backtrack[curr.first][curr.second];
    }
    ans.push_back(start);
    cout << ans.size() - 1 << endl;
    reverse(ans.begin(), ans.end());

    for (int i = 1; i < ans.size(); i++) {
        pii a = ans[i-1];
        pii b = ans[i];

        if (a.first == b.first) {
            if (a.second > b.second) {
                cout << "L";
            } else {
                cout << "R";
            }
        }

        if (a.second == b.second) {
            if (a.first > b.first) {
                cout << "U";
            } else {
                cout << "D";
            }
        }
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
