#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

void solve(){
    int n;
    cin >> n;
    string x, y;
    cin >> x >> y;
    int ans = 0;
    vector<int> pref1(n, 0);
    vector<int> pref2(n, 0);
    for (int i = 1; i + 1 < n; i++) {
        pref1[i] = (x[i] == '.');
        pref2[i] = (y[i] == '.');
        if(i){
            pref1[i] += pref1[i - 1];
            pref2[i] += pref2[i - 1];
        }
        char cx = x[i];
        char cy = y[i];
        if (x[i - 1] == '.' && x[i + 1] == '.' && y[i - 1] == 'x' && y[i] == '.' && y[i + 1] == 'x')
            ans++;
        if (y[i - 1] == '.' && y[i + 1] == '.' && x[i - 1] == 'x' && x[i] == '.' && x[i + 1] == 'x')
            ans++;
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
