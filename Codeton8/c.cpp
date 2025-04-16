#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n, x , y;
    cin >> n >> x >> y;
    vector<int> arr(x);
    for(int& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int i = 2; i < x; i++){
        ans++;
        if(arr[i] - arr[i - 1] == 2)
            ans++;
    }
    if(n - (arr.back() - arr[0]) == 2)
        ans++;
    if(arr[1] - arr[0] == 2)
        ans++;

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
