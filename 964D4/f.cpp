#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;
const int mod = 1e9 + 7;


#define ll long long

const int MAX = 2e5 + 5, MOD = 1e9 + 7;

ll fact[MAX], ifact[MAX];

ll bpow(ll a, int p){
    ll ans = 1;

    for (;p; p /= 2, a = (a * a) % MOD) 
        if (p & 1) 
            ans = (ans * a) % MOD;

    return ans;
}
ll ncr(int n, int r){
    if (n < 0)
        return 0;
    if (r > n)
        return 0;

    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int l = (k - 1) / 2;
    vector<int> pref(n, 0);
    int ans = 0;
    for(int i = 0; i < n; i++)
        pref[i] = arr[i] + (i ? pref[i - 1] : 0);
    int ones = pref[n - 1];
    for(int cnt_ones = k / 2 + 1; cnt_ones <= min(ones, k); ++cnt_ones) {
        ans += ncr(ones, cnt_ones) * ncr(n - ones, k - cnt_ones) % mod;
        ans %= mod;
    }
    cout << ans % mod<< "\n";

}


int32_t main(){
    fast;
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