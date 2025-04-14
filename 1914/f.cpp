#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;

vector<int> adj[ maxN ];
int sz[ maxN ];

int dfs_sz(int curr){
    int ans = 1;
    for(auto next : adj[curr])
        ans += dfs_sz(next);
    return sz[curr] = ans;
}

int search(int curr, int k){

    int max_node = -1;
    int max_size = 0;

    for(auto next: adj[curr]){
        if(max_node == -1 || sz[next] > max_size){
            max_size = sz[next];
            max_node = next;
        }
    }
    int curr_size = sz[ curr ] - 1;
    if(max_size - k <= curr_size - max_size)
        return (curr_size - k) / 2;

    int curr_ans = curr_size - max_size  ;
    return curr_ans + search( max_node, max(0, k + curr_ans - 1 ));
}

void solve(){

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        adj[i].clear();

    for(int i = 2; i <= n; i++){
        int parent ;
        cin >> parent;
        adj[parent].push_back(i);
    }

    dfs_sz(1);

    cout << search(1, 0) << endl;
}


int main(){
    //freopen("input.txt", "r", stdin); 
    //reopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
