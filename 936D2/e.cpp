#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int mod = 1e9 + 7;

int factorial[N] = {}, inv_factorial[N] = {};

int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int mul(int x, int y) {
  return x * 1LL * y % MOD;
}

int binpow(int x, int y) {
  int z = 1;
  while (y) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}

long long binomial_coefficient(int n, int k) {
    return max(1LL, factorial[n] * inv_factorial[k] % mod * inv_factorial[n - k] % mod);
}

int calc(vector<int>& arr){
    int n = arr.size();
    int curr_count = arr.back();
    int ans = 1;
    for(int i = n - 1; i > 0; i--){
        int gap = arr[i] - arr[i - 1] - 1;
        ans *= binomial_coefficient(curr_count - 2, gap) % mod * factorial[gap] % mod;
        ans %= mod;
        curr_count -= (gap + 1);
    }
    //cout << ans << "---\n";
    return ans;
}

void solve(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> a(m1);
    vector<int> b(m2);
    for(int& i : a)
        cin >> i;
    for(int& i : b)
        cin >> i;
    if(a[m1 - 1] != b[0] || b[m2 - 1] != n || a[0] != 1){
        cout << "0\n";
        return;
    }
    int ans = binomial_coefficient(n - 1, a.back() - 1);

    for(int& i : b)
        i = n - i + 1;
    reverse(b.begin(), b.end());
    ans *= calc(a);
    ans %= mod;
    ans *= calc(b);
    ans %= mod;

    cout << ans << '\n';
}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    int inv[200005] = {};
    int scount = 200002;
    factorial[0] = inv_factorial[0] = 1;
    factorial[1] = inv[1] = inv_factorial[1] = 1;
    for (int i = 2; i <= scount + 1; ++i) {
            factorial[i] = mul(factorial[i - 1] , i )% mod;  
    }

    inv_factorial[scount] = binpow(factorial[scount], MOD - 2);
    for (int i = scount; i > 0; --i)
        inv_factorial[i - 1] = mul(inv_factorial[i], i);

    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}


