#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
const int N = 2e5 + 5;

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

void solve(){
    int n, q;
    cin >> n >> q;
 
    string s;
    cin >> s;
 
    vector<int> f1(n ), f2(n );
 
    for(int i = n - 1;i >= 0;i --){
        f1[i] = i + 1 < n && s[i] == s[i + 1] ? f1[i + 1] : i ;
        f2[i] = i + 2 < n && s[i] == s[i + 2] ? f2[i + 2] : i ;
    }
 
    auto rad = manacher(s);


    while(q--){
        int l,r;
        cin >> l >> r;
        l--,r--;
 
        long long ans = 0;
        int len = r - l + 1;

        if (l == r){
            cout << 0 << "\n";
            continue;
        }
        
 
        if(f1[l] < r) {
            int mx = (len - 1) / 2;
            ans += 1ll * (mx) * (mx + 1);
        }
 
        if(f2[l] < r - 1|| f2[l + 1] < r - 1){
            int mx = len / 2;
            ans += 1ll * (mx) * (mx + 1) - mx;
            ans -= 1;
        }

        if(rad[l + r] < len){
            ans += len;
        }
 
        cout << ans << endl;
    }
}
class Solution{
public:
    int findMinArrowShots(vector<vector<int>>& points){
        sort(points.begin(), points.end());
        vector<int> curr_window = {-1, -1};
        int ans = 0;
        for(auto& p : points){
            if(p[0] > curr_window[1]){
                ans++;
                curr_window = {p[0], INT_MAX;
            }else if(curr_window[1] >= p[1]){
                curr_window[1] = p[1];
            }
        }
        return ans;
    }
};
int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
