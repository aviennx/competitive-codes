#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    map<int,int> mp;
    for(int i  = 1; i <= n; i++){
        if(i < n){
            mp[(i) * (n - i)] += (arr[i + 1] - arr[i] - 1);
        }
        int v = i - 1 + n - i + (n - i) * (i - 1);
        mp[v]++;
    }
    while(q--){
        int k;
        cin >> k;
        cout << mp[k] << ' ';
    }
    cout << '\n';
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
