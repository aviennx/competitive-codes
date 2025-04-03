#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define ll long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 20000;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAX = 20000;

int add(int a, int b) {
    if (a + b >= mod)
        return a + b - mod;
    return a + b;
}

int sub(int a, int b) {
    if (a < b)
        return a + mod - b;
    return a - b;
}

int mul(int a, int b) {
    return (int)((1ll * a * b) % mod);
}

ll fact[MAX], ifact[MAX];

ll bpow(ll a, int p){
    ll ans = 1;

    for (;p; p /= 2, a = (a * a) % MOD) 
        if (p & 1) 
            ans = (ans * a) % MOD;

    return ans;
}
ll C(int n, int r){
    if (n < 0 || r < 0)
        return 0;
    if (r > n)
        return 0;
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}


void solve(){
    int n;
    cin >> n;
    int ans = 1;
    for (int k = 1; k <= n; k++) {
        if (2 * k >= n) {
            ans = add(ans, mul(2 * k + 1, C(n, k)));
            continue;
        }
        for (int m = k + 1; m <= 2 * k + 1; m++) {
            int c = mul(C(m - 1, m - 1 - k), C(n - m, 2 * k + 1 - m));
            ans = add(ans, mul(mul(C(m - 1, m - 1 - k), C(n - m, 2 * k + 1 - m)), m));
        }
    }
    cout << ans << '\n';
}


int32_t main(){

    for (int i = 0; i < MAX; i++)
        fact[i] = !i ? 1 : fact[i - 1] * i % MOD;
    
    for (int i = MAX - 1; i >= 0; i--)
        ifact[i] = (i == MAX - 1) ? bpow(fact[MAX - 1], MOD - 2) : ifact[i + 1] * (i + 1) % MOD;


    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}


