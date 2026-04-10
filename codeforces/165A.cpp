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
    int n;
    cin >> n;

    vector<pii> plano(n);
    
    int maiorX = 0;
    int menorX = 2000;
    int maiorY = 0;
    int menorY = 2000;

    for (int i = 0; i < n; i++) {
        int x;
        int y;

        cin >> x >> y;

        menorX = min(menorX, x);
        maiorX = max(maiorX, x);
        menorY = min(menorY, y);
        maiorY = max(maiorY, y);
        
        plano[i].first = x;
        plano[i].second = y;
    }

    int qntd = 0;

    for (pii par : plano) {

        if (par.first == menorX || par.first == maiorX || par.second == menorY || par.second == maiorY) {
            continue;
        }

        vi check = { 0, 0, 0, 0 };

        for (pii alvo : plano) {
            if (par.first < alvo.first && par.second == alvo.second && check[0] == 0) {
                check[0] = 1;
            }

            if (par.first > alvo.first && par.second == alvo.second && check[1] == 0) {
                check[1] = 1;
            }

            if (par.first == alvo.first && par.second < alvo.second && check[2] == 0) {
                check[2] = 1;
            }

            if (par.first == alvo.first && par.second > alvo.second && check[3] == 0) {
                check[3] = 1;
            }

            if (accumulate(check.begin(), check.end(), 0) == 4) {
                qntd++;
                break;
            }
        }
    }

    cout << qntd << endl;
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
