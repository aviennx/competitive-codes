#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 
using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second


void solve(){
    int n; cin >> n;
    int ans = 0;
    vector <int> f(n + 1, 0);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        f[x]++;
    }
    
    int cnt = 0;
    for (int i = 0; i <= n; i++){
        ans += (f[i] * (f[i] - 1) / 2) * cnt;
        ans += (f[i] * (f[i] - 1) * (f[i] - 2)) / 6;
        cnt += f[i];
    }
    
    cout << ans << "\n";

}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
