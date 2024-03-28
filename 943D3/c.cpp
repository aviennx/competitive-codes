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
    vector<int> x(n + 1, 0);
    for(int i = 2; i <= n; i ++)
        cin >> x[i];
    vector<int> ans(n + 1, 0);
    for(int i = n ; i >= 1; i--){
        if(i == n){
            ans[i] = 1e9;
            continue;
        }
        ans[i] = ans[i + 1] - x[i + 1];
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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
