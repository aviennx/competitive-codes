#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>


const int N = 2e5 + 5;

const int MOD = 998244353;

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

int csi[2000001] = {};
int factorial[2000001] = {}, inv_factorial[2000001] = {}, mod = 998244353;

int binomial_coefficient(int n, int k) {
    return max(1 , mul(mul(factorial[n], inv_factorial[k]) % mod , inv_factorial[n - k]));
}



void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    vector<int> pref_a(n), pref_b(n);
    int gcount = 0, scount = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        gcount += a[i];
        pref_a[i] = a[i] + (i ? pref_a[i - 1] : 0);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        scount += b[i];
        pref_b[i] = b[i] + (i ? pref_b[i - 1] : 0);
    }
    int inv[2000000] = {};
    factorial[1] = inv[1] = inv_factorial[1] = 1;
    for (int i = 2; i <= scount + 1; ++i) {
            factorial[i] = mul(factorial[i - 1] , i )% mod;  
    }

    inv_factorial[scount] = binpow(factorial[scount], MOD - 2);
    for (int i = scount; i > 0; --i)
        inv_factorial[i - 1] = mul(inv_factorial[i], i);


    for(int i = 0; i <= scount + 1; i++){
        csi[i] = add(binomial_coefficient(scount, i), (i ? csi[i - 1] : 0));
    }
    int div = binpow(2, scount);
    div = binpow(div, mod - 2);
    while(q--){
        int l , r;
        cin >> l >> r;
        l--, r--;
        int my_g = pref_a[r] - (l ? pref_a[l - 1] : 0);
        int my_s = pref_b[r] - (l ? pref_b[l - 1] : 0);
        int sum = mul(2 , my_g) - gcount + my_s;
        if(sum <= 0){
            cout << "0 ";
            continue;
        }
        int ans = csi[min(scount, sum - 1)];
        ans = mul(ans,div);
        cout << ans << " ";
    }
    cout << '\n'; 
}


int main(){
    fast;
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
