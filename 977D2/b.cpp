#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    map<int,multiset<int>> mp;
    vector<int> arr(n);
    for(int& i : arr){
        cin >> i;
        mp[i % k].insert(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(mp[i % k].empty()){
            cout << ans << '\n';
            return;
        }
        auto it = mp[i % k].begin();
        if(*it > i){
            cout << ans << '\n';
            return;
        }
        mp[i % k].erase(it);
        ans++;
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
