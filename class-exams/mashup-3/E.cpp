#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;

#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mkp make_pair
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
    vector<int> nums = {4, 8, 15, 16, 23, 42};
    vector<int> guess(6);
    int mul1, mul2, mul3, mul4;

    cout << "? 1 2" << endl;
    cin >> mul1;
    cout << "? 1 3" << endl;
    cin >> mul2;
    cout << "? 4 5" << endl;
    cin >> mul3;
    cout << "? 4 6" << endl;
    cin >> mul4;

    // solve first trio
    sort(nums.begin(), nums.end());
    do {
        if ((nums[0] * nums[1] == mul1) && (nums[0] * nums[2] == mul2)) {
            guess[0] = nums[0];
            guess[1] = nums[1];
            guess[2] = nums[2];
            break;
        }
    } while (next_permutation(nums.begin(), nums.end()));

    // remove the 3 guesses, sort and do it again
    for (int i = 0; i < 3; i++) {
        nums.erase(remove(nums.begin(), nums.end(), guess[i]), nums.end());
    }

    sort(nums.begin(), nums.end());
    do {
        if ((nums[0] * nums[1] == mul3) && (nums[0] * nums[2] == mul4)) {
            guess[3] = nums[0];
            guess[4] = nums[1];
            guess[5] = nums[2];
            break;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    
    cout << "! ";
    for (int a : guess) {
        cout << a << " ";
    } cout << endl;
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
