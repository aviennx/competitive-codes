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
    vector<int> arr(k);
    for(int& i : arr)
        cin >> i;
    int ans = 0;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < k - 1; i++){
        ans += (2 * arr[i] - 1);
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
