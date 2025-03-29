#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        for (int &j = z[i]; i + j < n && s[j] == s[i + j]; j++);
        if (z[i] > r - i + 1)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve(){
    int n, l1, r1;
    cin >> n >> l1 >> r1;
    string s;
    cin >> s;
    int k = l1;
    vector<int> z = z_function(s);
    auto check = [&](int pref_len){
        int i = 0;
        int cnt = 0;
        while(i < n){
            if(z[i] >= pref_len){
                cnt++;
                i += pref_len;
            }else
                i++;
        }
        return cnt;
    };
    int ans = 0;
    int l = 1, r = n ;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid) >= k){
            ans = max(ans, mid);
            l = mid + 1;
        }else
            r = mid - 1;
    }
    cout << ans << '\n';
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
