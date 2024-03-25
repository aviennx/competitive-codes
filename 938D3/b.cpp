#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e6 + 5;
int a[N], b[N];
void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    for (int i = 1; i <= n * n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n * n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[(i - 1) * n + j] = a[1] + (i - 1) * c + (j - 1) * d;
        }
    }
    sort(b + 1, b + 1 + n * n);
    bool ob = true;
    for (int i = 1; i <= n * n; i++) {
        if (a[i] != b[i]) {
            ob = false;
        }
    }
    cout << (ob ? "Yes\n" : "No\n");
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
