#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
        int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
 
    int mx = a[0];
    for(int x: a) mx = max(x, mx);
 
 
    map <int, set <int>> to_delete;
    for(int i = 0; i < n; ++i) to_delete[a[i]].insert(i);
 
    set <pair <int, int>> cur_int;
 
    cur_int.insert({0, n - 1});
 
    int sz[100010];
    memset(sz, 0, sizeof sz);
 
    sz[1] = 1;
 
    for(int i = 1; i <= 100000; ++i){
 
 
        for(int x: to_delete[i]){
 
 
            pair <int, int> q = *(--cur_int.upper_bound({x, 1000000}));
 
            cur_int.erase(q);
            if(x > q.first) cur_int.insert({q.first, x - 1});
            if(q.second > x) cur_int.insert({x + 1, q.second});
 
 
 
        }
 
        sz[i + 1] = cur_int.size();
 
    }
 
 
    for(int i = 1; i <= mx; ++i){
 
        int ans = 0;
        for(int q = 1; q <= 100005; q += i) ans += sz[q];
 
        cout << ans << " ";
 
    }
    cout << "\n";
   


}


int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
