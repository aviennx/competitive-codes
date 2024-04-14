#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")


#define ll long long

const int MAX = 2e6 + 5, MOD = 998244353;

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
    int l, n;
    cin >> l >> n;
    int ans = 2 * ncr(l, 2 * n);
    ans %= MOD;
    int cnt = 0;
    for(int i = 0; i <= l ; i += 2){
        int v = 2 * ncr(i / 2 + n - 1, n - 1) * ncr(l - n - i, n);
        v %= MOD;
        cnt = (cnt + v) % MOD;
    }
    ans = (ans - cnt);
    if(ans < 0)
        ans += MOD;
    cout << ans << '\n';

}

int32_t main(){
    fast;
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 

    for (int i = 0; i < MAX; i++)
        fact[i] = !i ? 1 : fact[i - 1] * i % MOD;
    
    for (int i = MAX - 1; i >= 0; i--)
        ifact[i] = (i == MAX - 1) ? bpow(fact[MAX - 1], MOD - 2) : ifact[i + 1] * (i + 1) % MOD;


 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
