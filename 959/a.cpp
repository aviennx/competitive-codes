#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m, 0)), b(n , vector<int> (m, 0));
    for(auto& v : a)
        for(int& i : v)
            cin >> i;
    if(n == 1 && m == 1){
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << a[(i + 1) % n][(j + 1) % m] << ' ';
                }
                cout << '\n';
            }
    cout << '\n';


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