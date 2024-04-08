#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
const int N = 2e5 + 5;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i++){
        int l = 0;
        cin >> l;
        for(int j = 0; j < l; j++){
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }
    int mx = 0;
    vector<pair<int,int>> a;
    for(auto& v : arr){
        int sz = v.size();
        vector<int> have(sz + 5, 0);
        for(int i : v)
            if(i <= sz + 3)
                have[i] = 1;
        int curr_mex = 0;
        int m1 = -1, m2 = -1;
        for(int i = 0; i <= sz + 2; i++){
            if(!have[i]){
                if(m1 == -1){
                   m1 = i;
                }else{
                    m2 = i;
                    break;
                }
            }
        }
        a.push_back({m1, m2});
        mx = max(mx, m2);
    }
    int ans = mx * (m + 1);
    cout << mx << " ";
    if (mx >= m){
        cout << ans << '\n';
        return;
    }
    ans = mx * mx + (m - mx + 1) * ( m + mx ) / 2;
    cout << ans << '\n';
    return;
}



int32_t main(){
    fast;
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
