#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;


void dfs(vector<int> adj[],int dis[],int par[],int u,int p)
{
    par[u]=p;
    for(auto v:adj[u])
    {
        if(v!=p)
        {
            dis[v]=dis[u]+1;
            dfs(adj,dis,par,v,u);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dis[n],par[n];
    dis[0]=0;
    dfs(adj,dis,par,0,0);
    int r=0;
    for(int i=0;i<n;i++)
        if(dis[r]<dis[i])
            r=i;
    dis[r]=0;
    dfs(adj,dis,par,r,r);
    int l=r;
    for(int i=0;i<n;i++)
        if(dis[l]<dis[i])
            l=i;
    vector<int> diameter;
    int u=l;
    while(u!=r)
    {
        diameter.push_back(u);
        u=par[u];
    }
    diameter.push_back(r);
    int d = diameter.size();
    if(d % 2){
        int center = d / 2;
        cout << center + 1 << '\n';
        for(int i = 0; i <= center; i++)
            cout << diameter[center] + 1 << " " << i  << '\n';
        return;
    }else{
        int ops = ((n - 2)/4) + 1;
        int need = (d/2) - 1;
        int c1 = d / 2;
        int c2 = d / 2 - 1;
        if(d % 4 == 2)
            cout << d / 2 + 1 << '\n';
        else
            cout << d/ 2 << '\n';
        int start = 1;
        while (need >= 0){
            cout << diameter[c1]  + 1 << " " <<  start<< '\n';
            cout << diameter[c2] + 1 << " " << start << '\n';
            need -= 2;
            start += 2;
        }
    }
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
