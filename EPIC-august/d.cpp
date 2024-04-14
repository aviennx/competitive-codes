#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
/*
at 1 values are :
1 0 11 3
2 3 
at 2 values are :
2 1 22 1

at 3 values are :
3 1 33 1

1 : 2 : 3 : 
3base cnt '
1 : 1 : 2 : 2 : 3 : 3 : 
1 : 1 : 2 : 2 : 3 : 3 : 
YES
3 1 : 1 : 2 : 2 : 3 : 3 : 
1 : 1 : 2 : 2 : 3 : 3 : 
YES
3 0 : 1 : 1 : 3 : 3 : 
0 : 1 : 1 : 3 : 3 : 
NO
2 
5 
*/
const int MAX_N = 2e5 + 5;
set<int> adj[MAX_N] = {};
int curr_index[MAX_N] = {};
int sz[MAX_N] = {};
int parent[MAX_N] = {};
int perm[MAX_N] = {};
int calc(int x){
    //cout << x << " : ";
    if(adj[x].size() == 0)
        return 1;
    int last_index = curr_index[x] + sz[x];
    int i = curr_index[x];
    int li = *adj[x].begin();
    int ri = *--adj[x].end() + sz[perm[*--adj[x].end()]];
    return (li > i) && (ri <= last_index);
}
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        adj[i].clear();
    }
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        parent[i] = x;
    }
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        curr_index[x] = i;
        adj[parent[x]].insert(i);
        perm[i] = x;
    }
    for(int i = n ; i >= 1; i--){
        if( parent[i] == 0)
            continue;
        sz[parent[i]] += sz[i];
    }
    /*for(int i = 1; i <= n; i++){
        cout << "at " << i << " values are :\n";
        cout << i << " " << parent[i] << " " << perm[i] << curr_index[i] << " " << sz[i] << '\n';
        for(int j : adj[i])
            cout << j << " ";
        cout << '\n';

    }*/
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += calc(i);
    }
    //cout << '\n';
    //cout << cnt << "base cnt '\n";
    while(q--){
        
        int cl, cr;
        cin >> cl >> cr;
        int node_l = perm[cl] , node_r = perm[cr];
        int pl = parent[node_l], pr = parent[node_r];
        set<int> fix = {node_l, node_r, pl, pr};
        for(int i : fix){
            //cout << i << " : " ;
            if(i)
            cnt -= calc(i);
        }
        //cout << '\n';
        adj[pl].erase(cl);
        adj[pr].erase(cr);
        curr_index[node_l] = cr;
        curr_index[node_r] = cl;
        swap(perm[cl], perm[cr]);
        adj[pl].insert(cr);
        adj[pr].insert(cl);
        for(int i : fix){
            //cout << i << " : " ;
            if(i)
            cnt += calc(i);
        }
        //cout << '\n';
        yesno(cnt == n);
        //cout << cnt << ' ';
    }
    //cout << '\n';
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
