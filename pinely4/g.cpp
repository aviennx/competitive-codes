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
    vector<int> arr(n - 1);
    for(int& i : arr)
        cin >> i;
    vector<int> adj[n];
    vector<int> deg(n, 0);
    for(int i = 0; i < n - 1; i++){
        arr[i]--;
        int v = i + 1;
        int u = arr[i];
        adj[u].push_back(v);
        deg[u]++;
        deg[v]++;
    }
    vector<int> vals;
    vector<int> visited(n, false);
    for(int i = 1; i < n; i++){
        if(deg[i] != 1 || visited[i])
            continue;
        int val = 0;
        int curr = i;
        while(curr != 0 && !visited[curr]){
            visited[curr] = 1;
            val++;
            curr = arr[i - 1];
        }
        vals.push_back(val);
    }
    int ans = 0;
    for(int i : vals)
        ans ^= i;
    if(ans)
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
   


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
