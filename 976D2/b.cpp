#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;
int MOD = 1e9 + 7;
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
void balance(int& a, int b){
    while( a * a > b)
        a--;
    while((a + 1) * (a + 1) <= b)
        a++;
}

int getSqrt(int x) {
    int lo = 0, hi = 1e9, c = 0;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if((mid * mid) <= x) {
            c = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    return c;
}

void solve(){
    int n;
    cin >> n;
    int l = 1, r = 2e18;
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(mid >= n + getSqrt(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
