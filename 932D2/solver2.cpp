#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;


int countSignals(vector<int> frequencies, vector<vector<int>> filterRanges){
    int low = 0, high = INT_MAX;
    for(auto& v: filterRanges){
        low = max(low , v[0]);
        high = min(high, v[1]);
    }
    int ans = 0;
    for(int i : frequencies){
        if(i <= high && i >= low)
            ans++;
    }
    return ans;
}


void solve(){
    int n;
        cin >> n;
        vector<int> lrr(n), rrr(n);
        for (int i = 0; i < n; i++) {
            cin >> lrr[i] >> rrr[i];
        }
        vector<vi> a(31, vi(n)), b(31, vi(n));
        for (int i = 30; i >= 0 ; i--) {
            for (int j = 0; j < n; j++) {
                if (j != 0)a[i][j] = a[i][j - 1];
                if (j != 0)b[i][j] = b[i][j - 1];
                if ((1 << i) <= rrr[j]) {
                    a[i][j]++;
                }
                if ((1 << i) <= rrr[j] && lrr[j] < (1 << i)) {
                    b[i][j]++;
                }
                if (rrr[j] >= (1 << i) && lrr[j] < (1 << i)) {
                    lrr[j] = 0;
                    rrr[j] = rrr[j] ^ (1 << i);
                }
                else if (lrr[j] >= (1 << i)) {
                    rrr[j] = rrr[j] ^ (1 << i);
                    lrr[j] = lrr[j] ^ (1 << i);
                }
            }
        }
        int q;
        cin >> q;
        wd(a,b);
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            int ans = 0;
            bool ok = 1;
            for (int j = 30; ok && j >= 0 ; j--) {
                if (a[j][r] - ((l == 0) ? 0 : a[j][l - 1]) >= 2 && b[j][r] - ((l == 0 ? 0 : b[j][l - 1])) >= 1) {
                    for (int k = j; k >= 0 ; k--) {
                        ans |= (1 << k);
                    }
                    ok = 0;
                }
                else if (a[j][r] - ((l == 0) ? 0 : a[j][l - 1]) >= 1) {
                    ans |= 1 << j;
                }
            }
            cout << ans << " ";
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