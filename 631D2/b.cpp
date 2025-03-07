#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
        int n;
        cin >> n;
 
        vector<int> a(n+1);
        int tot = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], tot += a[i];
    
        int sum = 0;
        vector<pair<int, int>> ans;
        vector<int> distinct_pref(n + 1,0),distinct_suf(n+2,0);
 
        map<int, int> cnt1,cnt2;
 
        for (int i = 1; i <= n; i++) {
            distinct_pref[i] += distinct_pref[i-1];
            if (cnt1[a[i]]==0){
                 distinct_pref[i]++;
            }
            cnt1[a[i]]++;                                        
        }
 
        for (int i = n; i >= 1; i--) {
            distinct_suf[i] += distinct_suf[i+1];
            if (cnt2[a[i]]==0){
                distinct_suf[i]++;
            }
            cnt2[a[i]]++;
        }
        
        for (int l1 = 1; l1 < n; l1++) {
            sum += a[l1];   
            if (distinct_pref[l1] == l1 && distinct_suf[l1+1]==n-l1&&sum == l1 * (l1 + 1) / 2 && (tot - sum) == (n - l1) * (n - l1 + 1) / 2) {
                ans.push_back({l1, n - l1});
            }   
        }
 
        cout << (int)ans.size() << '\n';
        for (auto u : ans) cout << u.first << " " << u.second << '\n';
   


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
    return 0;
}
