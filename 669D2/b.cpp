#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

void solve() {
    int n;
    cin >> n;
    int a[n];
    int mi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mi = (a[i] > a[mi] ? i : mi);
    }
    vector<int> b(n);
    b[0] = a[mi]; a[mi] = 0;
    int cg = b[0];
    for (int i = 1; i < n; i++) {
        int ci = 0, cans = 0;
        for (int j = 0; j < n; j++)
            if (a[j] && __gcd(a[j], cg) > cans) {
                cans = __gcd(a[j], cg);
                ci = j;
            }
        b[i] = a[ci];
        cg = cans;
        a[ci] = 0;
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << '\n';
}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
