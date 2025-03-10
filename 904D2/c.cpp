#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

 
void mxfreq(multiset<pair<int,int>>&mt, int &ans){
    int cur=0;
    for(auto it:mt){
        cur+=it.second;
        ans =max(ans,cur);
    }
}
void solve() {
    int n,m; cin >> n >> m;
    multiset<pair<int,int>>mt;
    vector<pair<int,int>>vp(n);
    for(int i = 0; i < n; i++){
        cin >> vp[i].first >> vp[i].second;
        if (vp[i].first!=1) {
            mt.insert({vp[i].first, 1});
            mt.insert({vp[i].second + 1, -1});
        }
    }
 
    int ans =0;
    mxfreq(mt,ans);
    mt.clear();
    for (auto it :vp){
       if (it.second==m)continue;
       mt.insert({it.first,1});
       mt.insert({it.second+1,-1});
   }
    mxfreq(mt,ans);
    cout <<ans << '\n';
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
