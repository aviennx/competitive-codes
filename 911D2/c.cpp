#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;


int dfs(vector<pair<int,int>>& tree, int i, int p, string& s){
    if(tree[i].first == 0 && tree[i].second == 0)
        return 0;
    int ans = INT_MAX, l = 1e9, r = 1e9;
    if(tree[i].first != 0){
        l = dfs(tree, tree[i].first, i, s);
    }
    if(tree[i].second != 0){
        r = dfs(tree, tree[i].second, i, s);
    }
    if(s[i] == 'L')
        r++;
    if(s[i]=='R')
        l++;
    ans = min(l, r);
    if(s[i] == 'U')
        return 1 + ans;
    return ans;
}


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "#" + s;
    vector<pair<int,int>> tree(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> tree[i].first >> tree[i].second;
    }
    cout << dfs(tree, 1, 0, s) << '\n';



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
