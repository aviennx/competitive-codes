#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n, q; cin >> n >> q;
        vector<int> a(n);
        set<int> pos;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) pos.insert(i);
        }
        while (q--) {
            int cmd; cin >> cmd;
            if (cmd == 1) {
                int v; cin >> v;
                int num = pos.size();
                if ((v - num) & 1) {
                    if (num == 0) cout << "NO";
                    else {
                        int s1 = 2 * *pos.rbegin() - (num - 1);
                        int s2 = 2 * (n - *pos.begin() - 1) - (num - 1);
                        if (v <= max(s1, s2)) cout << "YES";
                        else cout << "NO";
                    }
                } else {
                    if (v <= 2 * n - num) cout << "YES";
                    else cout << "NO";
                }
                cout << '\n';
            } else {
                int i; cin >> i; i--;
                pos.erase(i);
                cin >> a[i];
                if (a[i] == 1) pos.insert(i);
            }
        }
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
