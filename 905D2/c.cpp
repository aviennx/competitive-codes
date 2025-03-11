#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 10001;
const ll D[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
 
void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    map <int, int> mp, check;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    int first = 0, ans = 0;
    for(int i = 0; i < n; i++){
        check[a[i]]++;
        if(check[a[i]] == 1){
            first++;
        }
        if(mp[a[i]] == check[a[i]]) ans += first;
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
