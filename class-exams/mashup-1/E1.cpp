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

// 7
// 2 7 4 6 9 11 5

// 2 4 5 6 7 9 11

    int n;
    cin >> n;

    vi fash(n);
    for (int i = 0; i < n; i++) cin >> fash[i];
    sort(fash.begin(), fash.end());

    int left = 0;
    int right = n - 1;

    if ((fash[left] + fash[right]) % 2 == 0) {
        cout << 0 << endl;
        return;
    }

    int count_left = 0;
    int count_right = 0;

    // aqui, um é par e o outro é impar, então a gente conta
    while (true) {
        int last_left = fash[left];
        int last_right = fash[right];

        count_left++;
        count_right++;

        left++;
        right--;

        if ((fash[left] + last_left) % 2 != 0) {
            cout << count_left << endl;
            break;
        }

        if ((fash[right] + last_right) % 2 != 0) {
            cout << count_right << endl;
            break;
        }
    }
}

const bool TEST_CASES = 1;

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
