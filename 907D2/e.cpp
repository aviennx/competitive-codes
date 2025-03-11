#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    unordered_map<int,int> parents;
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> to_add;
    parents[1] = 0;
    to_add[1] = 0;
    int curr_count = 1;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(t == 1){
            curr_count++;
            int parent;
            cin >> parent;
            adj[parent].push_back(curr_count);
            parents[curr_count] = parent;
            to_add[curr_count] = -1 * to_add[parent];
        }else{
            int v, x;
            cin >> v >> x;
            to_add[v] += x;
        }
    }
    vector<int> ans(curr_count);
    function<void(int,int,int)> dfs = [&](int curr, int prev, int val)->void{
        val += to_add[curr];
        ans[curr - 1] = val;
        for(int next : adj[curr]){
            if(next == prev)
                continue;
            dfs(next, curr, val);
        }
    };
    dfs(1, 0, 0);
    for(int i : ans)
        cout << i << " ";
    cout << '\n';


   


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
