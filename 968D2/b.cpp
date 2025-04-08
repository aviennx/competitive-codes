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
    int mn = LLONG_MAX, mx = -1;
    for(auto& i : arr){
        mn = min(i , mn);
        mx = max(i, mx);
    }
    int last = arr.back();
    if(n == 2){
        cout << mx << '\n';
        return;
    }
    sort(arr.begin(), arr.end());
    int md = n / 2;
    int v = arr[md];
    cout << v << '\n';
    return;

   


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
