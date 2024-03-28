#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
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
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    vector<int> z = z_function(s);
    vector<int> dp(n + 1, -1);
    auto getMaxSegments = [&](int len){
        if(len == 0)
            return INT_MAX;
        if(len > n)
            return 0;
        if(dp[len] != -1)
            return dp[len];
        int i = 0;
        int cnt = 0;
        while(i < n){
            if(z[i] >= len){
                cnt++;
                i += len;
            }else
                i++;
        }
        return dp[len] = cnt;
    };
    auto getMaxl = [&](int segments){
        int l1 = 0, r1 = n;
        int ans = 0;
        while(l1 <= r1){
            int mid = (l1 + r1) / 2;
            if(getMaxSegments(mid) >= segments){
                ans = max(ans, mid);
                l1 = mid + 1;
            }else
                r1 = mid - 1;
        }
        return ans;
    };
    int seg_range = l;
    while(seg_range <= r){
        int best_len = getMaxl(seg_range);
        int best_upto = getMaxSegments(best_len);
        while(seg_range <= best_upto && seg_range <= r){
            cout << best_len << " ";
            seg_range++; 
        }
    }
    vector<pair<int,int>> q = {{1,0}};
    for(auto [x, y] : q){
        cout << x << " " << y << " == \n";
    }
    cout << '\n';
}

int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    cout << "Doooo//ne\n";
    return 0;
}
