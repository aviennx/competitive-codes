#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

//

void solve(){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &ai: a) {
            cin >> ai;
        }
        vector<vector<int>> v(2);
        //bool odd = true, even = true;
        for (int i = 0; i < n; i++) {
            v[a[i] % 2].push_back(a[i]);
        }
        if (v[0].empty() || v[1].empty()) {
            cout << 0 << endl;
        } else {
            sort(v[0].begin(), v[0].end());
            sort(v[1].begin(), v[1].end());
            int cur = v[1].back();
            int res = v[0].size();
            for (int vi: v[0]) {
                if (vi > cur) {
                    res++;
                    break;
                } else {
                    cur += vi; 
                }
            }
            cout << res << endl;
        }


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
