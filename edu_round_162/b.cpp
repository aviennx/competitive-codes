#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 
using int2 = pair<int,int>;

void solve(){
    int n, k;

    cin >> n >> k;

    vector<int> a(n), x(n);
    for (auto& it : a)
        cin >> it;
    for (auto& it : x)
        cin >> it;

    vector<long long> s(n + 1);

    for (int i = 0; i < n; ++i)
        s[abs(x[i])] += a[i];
    
    bool ok = true;
    long long lft = 0;

    for (int i = 1; i <= n; ++i) {
      lft += k - s[i];
      ok &= (lft >= 0);
    }

    cout << (ok ? "YES" : "NO") << '\n';
    
}


int main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
