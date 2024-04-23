#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n, m , k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    int prev = 0;
    long long ans = 0;
    for(int i = 0 ; i < n; i++){
        int curr = min(k , m);
        k -= curr;
        ans += arr[i] * curr;
        ans += prev * curr;
        prev += curr;
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
