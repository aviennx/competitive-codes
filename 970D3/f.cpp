#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define ll long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

long long mod = 1000000007;
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

int modPow(long long x, int y, int m)
{
    long long ans=1;
    if (y == 0)
        return 1;
    while(y>0){
        if(y % 2 == 1)
            ans = ans * x % m;
        y >>= 1;
        x = x * x % m;
    }
    return ans % m;
}
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int tot = 0, ts = 0;
    int x = n * (n - 1) / 2;
    int y = modPow(2, mod - 2, mod);
    x %= mod;
    for(int& i : arr){
        cin >> i;
        tot += i;
        ts += i * i;
        ts %= mod;
        tot %= mod;
    }
    int a = (tot * tot - ts) % mod;
    if(a < 0)
        a += mod;
    cout << (((a * y ) % mod) * modPow(x, mod - 2, mod)) % mod << endl;
}
int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
for (int i = 0; i < MAX; i++)
        fact[i] = !i ? 1 : fact[i - 1] * i % MOD;
    
for (int i = MAX - 1; i >= 0; i--)
    ifact[i] = (i == MAX - 1) ? bpow(fact[MAX - 1], MOD - 2) : ifact[i + 1] * (i + 1) % MOD;


    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
