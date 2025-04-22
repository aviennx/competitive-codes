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
    vector<int> a(n), b(n + 1);
    for(int& i : a)
        cin >> i;
    for(int& i : b)
        cin >> i;
    int last = INT_MAX;
    int c = b[n];
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(a[i] - b[i]);
        if(a[i] <= c && c <= b[i])
            last = 0;
        if(a[i] >= c && c >= b[i])
            last = 0;
        last = min(last, abs(c - a[i]));
        last = min(last, abs(c - b[i]));
    }
    cout << last + ans + 1 << '\n';
   


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
