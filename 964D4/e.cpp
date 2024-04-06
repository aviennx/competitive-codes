#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
const int MAX = 200'007;
const int MOD = 1'000'000'007;

int a[MAX], psum[MAX];

int f(int x) {
    int cnt = 0;
    while (x) {
        x /= 3;
        cnt++;
    }
    return cnt;
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << psum[r] - psum[l - 1] + a[l] << '\n';
}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    psum[0] = 0;
    for (int i = 1; i < MAX - 1; i++) {
        a[i] = f(i);
        psum[i] = psum[i - 1] + a[i];
    }
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
