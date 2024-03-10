 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll     long long
#define pb     push_back
 
int main()
{
    int n, t;
    cin>>n>>t;
 
    vector<vector<int>> graph(n);
    map<pair<int, int>, vector<int>> edgesTime;
 
    for(int j=0; j<t; j++)
    {
        int m;
        cin>>m;
 
        for(int i=0, u, v; i<m; i++)
        {
            cin>>u>>v;
            u--, v--;
 
            graph[u].pb(v);
            graph[v].pb(u);
 
            edgesTime[{u, v}].pb(j+1);
            edgesTime[{v, u}].pb(j+1);
        }
    }
 
    int k;
    cin>>k;
 
    vector<int> a(k);
    for(auto &e: a)     cin>>e;
 
    vector<set<int>> next(t+1);
    for(int i=0; i<k; i++)
        next[a[i]].insert(i+1);
 
    vector<int> dist(n, 1e9);
 
    dist[0] = 1;
 
    set<pair<int, int>> sp;
    sp.insert({dist[0], 0});
    int tmp;
 
    while(sp.size())
    {
        auto [d, u] = *sp.begin();
        sp.erase(sp.begin());
 
        if(dist[u] < d)     continue;
 
        for(auto v: graph[u])
        {
            tmp = 1e9;
 
            for(auto poss: edgesTime[{u, v}])
            {
                if(next[poss].lower_bound(d) == next[poss].end())       continue;
                tmp = min(tmp, *next[poss].lower_bound(d));
            }
 
            tmp++;
 
            if(dist[v] > tmp)
            {
                dist[v] = tmp;
                sp.insert({tmp, v});
            }
        }
    }
 
    if(dist[n-1] == 1e9)        dist[n-1] = 0;
 
    cout<<dist[n-1]-1<<"\n";
}