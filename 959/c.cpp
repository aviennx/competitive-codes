#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define ll long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

//const int N = 2e5 + 5;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n + 1, 0);
    for(int i = 0 ; i < n; i ++)
        cin >> arr[i + 1];
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + arr[i];
    vector<int> dp(n + 2, 0);
    for(int i = n; i >= 1; i--){
        auto it = upper_bound(pref.begin(), pref.end(), pref[i - 1] + x) - pref.begin();
        dp[i] = it - i;
        if(it + 1 < n + 2)
            dp[i] += dp[it + 1];
    }
    int ans = 0;
    for(int i : dp){
        ans += i;
    }
    cout << ans << '\n';


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