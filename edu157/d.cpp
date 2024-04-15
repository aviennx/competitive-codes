#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

void solve() {
    ll n;
    cin >> n;

    ll arr[n] = {0};
    for(ll i = 1; i < n; i++) cin >> arr[i];

    for(ll i = 1; i < n - 1; i++) arr[i + 1] ^= arr[i];

    for(ll k = 0; k < 32; k++) {
        ll curr = 0;
        for(ll i = 0; i < n; i++) {
            if((arr[i] & (1 << k)) != 0) curr++;
            else curr--;
        }
        if(curr > 0) for(ll i = 0; i < n; i++) arr[i] ^= (1 << k);
    }

    for(auto i : arr) cout << i << " ";
    cout << '\n';

}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}