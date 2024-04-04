#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    vector<int> dp(n);
    dp[n - 1] = (arr[n - 1] ? 1 : 0);
    for(int i = n - 2; i >= 0; i--){
        if(arr[i])
            dp[i] = dp[i + 1] + 1;
        if(i + 2 < n){
            dp[i] = min(dp[i], dp[i + 2] + max(arr[i], arr[i + 1]) / 2);
        }
    }
    cout << dp[0] << '\n';


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
