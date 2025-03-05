#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll x; cin >> x;
    if (x == 2) {
        cout << 1 << '\n' << 0 << '\n'; return;
    } 
    vector<ll> v = {1};
    ll cur = 2;
    while (cur*2 < x) {
        v.push_back(v.back()+1);
        cur <<= 1;
    }
    if (cur*2 == x) {
        v.push_back(v.back()+1);
    }
    else {
        ll more = x - cur;
        for (int i = 63; i >= 0; --i) {
            if (more & (1LL<<i)) {
                v.push_back(i+1);
            }
        }
    }
    cout << v.size() << '\n';
    for (ll x: v) cout << x << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc; while(tc--) solve();
}