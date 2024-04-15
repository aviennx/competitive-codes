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
    vector<int> arr(2 * n);
    for(int& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    int ans =abs( arr[n - 1] - arr[0]) + abs(arr[2 * n - 1] - arr[n]);
    cout << ans << '\n';
    for(int i = 0; i < n; i++)
        cout << arr[i] << " " << arr[i + n] << '\n';

   


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
