#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){

    int N, B, X;
    cin >> N >> B >> X;
 
    vector<int> C(N);
    for (auto &x : C) cin >> x;
 
    auto score = [&](int sc) {
      int total = -(sc-1) * X;
      for (auto x : C) {
        int base = x/sc;
        int p1 = x % sc;
        int p0 = sc - p1;
 
        int cnt = 0;
        cnt += p1*(p1-1)/2*(base+1)*(base+1);
        cnt += p0*(p0-1)/2*base*base;
        cnt += p0*p1*base*(base+1);
        total += cnt * B;
      }
      return total;
    };
 
    int ans = 0;
 
    int bl = 1, br = *max_element(begin(C), end(C));
    while (bl <= br) {
      int bm = midpoint(bl, br);
      int s0 = score(bm);
      int s1 = score(bm+1);
 
      ans = max(ans, max({s0, s1}));
 
      if (s0 < s1) {
        bl = bm+1;
      } else {
        br = bm-1;
      }
    }
 
    cout << ans << endl;
}


int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
