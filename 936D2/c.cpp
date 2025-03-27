#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

vector<int>G[N];
int n,k;
int mid;
int tot=0;
int dfs(int u,int fa){
    int ans = 1;
    for (int next:G[u]){
        if(next==fa)
            continue;
        ans += dfs(next,u);
        
    }
    if(ans >= mid && tot != 0) {
        tot--;
        return 0;
    }else
        return ans;
}
bool check(){
    tot=k;
    bool ans = dfs(1, 0) >= mid;
    return ans;
}
void solve() {
    cin >> n >> k;
    for (int i=1;i<=n;i++)G[i].clear();
    for (int i=1;i<=n-1;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int l=1,r=n;
    while(l<r){
        mid=(l+r+1)>>1;
        if(check()) l = mid;
        else r=mid-1;
    }
    cout << l << '\n';
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
