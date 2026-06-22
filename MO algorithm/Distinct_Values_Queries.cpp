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

// void solve(){
//     int n, q;
//     cin >> n >> q;

//     vi l(n);
//     for (int i = 0; i < n; i++) cin >> l[i];

//     while(q--) {
//         int a, b;
//         cin >> a >> b;
//         a--;

//         set<int> s;
//         for (int i = a; i < b; i++) s.insert(l[i]);
//         cout << s.size() << endl;
//     }

//     // O(q · n · log n)
//     // TLE confirmado, nenhum caso passa
// }

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    // compressão das coordenadas para valores 0..k-1
    vector<int> comp = x;

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int &value : x) value = lower_bound(comp.begin(), comp.end(), value) - comp.begin();
    int k = comp.size();

    // cada consulta = (l, r, idx), 0-indexado e intervalo inclusivo
    vector<tuple<int, int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries[i] = {a - 1, b - 1, i};
    }

    // tamanho do bloxo ~ n/sqrt(q)
    int len = max(1, (int)(n / sqrt((double)q + 1)));

    // Ordenação de Mo: Bloco de L crescente, R em ordem serpente
    sort(queries.begin(), queries.end(), [&](const auto &A, const auto &B) {
        int ba = get<0>(A) / len, bb = get<0>(B) / len;
        if (ba != bb) return ba < bb;
        return (ba & 1) ? (get<1>(A) > get<1>(B)) : (get<1>(A) < get<1>(B));
    });

    vector<int> count(k, 0), answer(q);
    int currL = 0, currR = -1, distinct = 0;

    for (auto [L, R, id] : queries) {
        while (currR < R) {
            currR++;
            if (count[x[currR]]++ == 0) distinct++;
        }
        while (currL > L) {
            currL--;
            if (count[x[currL]]++ == 0) distinct++;
        }
        while (currR > R) {
            if (--count[x[currR]] == 0) distinct--;
            currR--;
        }
        while (currL < L) {
            if (--count[x[currL]] == 0) distinct--;
            currL++;
        }

        answer[id] = distinct;
    }

    for (int i = 0; i < q; i++) cout << answer[i] << endl;
}

const bool TEST_CASES = 0;

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
