#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
         int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (k >= 3) {
            cout << 0 << endl;
           return;
        }
        sort(begin(a), end(a));
        int d = a[0];
        for (int i = 0; i < n - 1; i++) d = min(d, a[i + 1] - a[i]);
        if (k == 1) {
            cout << d << endl;
            return;
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) {
            int v = a[i] - a[j];
            int p = lower_bound(begin(a), end(a), v) - begin(a);
            if (p < n) d = min(d, a[p] - v);
            if (p > 0) d = min(d, v - a[p - 1]);
        }
        cout << d << endl;
}


int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
