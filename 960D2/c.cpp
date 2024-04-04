#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        ans += arr[i];
    }
    map<int,int> mp;
    int curr = 0;
    for(int i = 1; i <= n; i ++){
        if(++mp[arr[i]] >= 2){
             curr = max(curr, arr[i]);
        }
        arr[i] = curr;
    }
    map<int,int> mp2;
    for(int i = 1; i <= n; i++)
        ans += arr[i];
    curr = 0;
    for(int i = 1; i <= n; ++i){
        if(++mp2[arr[i]] >= 2)
            curr = max(curr, arr[i]);
        arr[i] = curr;
    }
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        pref[i] = pref[i - 1];
        pref[i] += arr[i];
    }
    for(int i : pref)
        ans += i;
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
