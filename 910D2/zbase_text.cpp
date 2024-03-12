#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> b;
    array<deque<int>, 26> st;
    for (int i = 0; i < n; ++i) {
        read(char, c);
        char c = s[i];
        st[c - 97].emplace_back(i);
    }
    for (int i = 0; i < m; ++i) {
        char c =
        b.emplace_back(c - 97);
    }
    array<int, 26> cnt {};
    for (int i = 0; i < m; ++i) {
        int c = b[i];
        if (st[c].empty()) {
            cout << "NO\n";
            return;
        }
        int idx = st[c].front();
        for (int i = 0; i < c; ++i) {
            while (st[i].size() && st[i].front() < idx) {
                st[i].pop_front();
            }
        }
        st[c].pop_front();
    }
    cout << "YES\n";
   


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
