#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using mytype = long double;
using ii = pair<lli,lli>;
using vii = vector<ii>;
using vi = vector<lli>;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define eb emplace_back
#define X first
#define Y second
const lli INF = 0xFFFFFFFFFFFFFFFLL;
void solve(){
    lli n;
    cin>>n;
    vector<vii> e(n);
    for(lli i=0;i<n-1;i++){
        lli A,B,x;
        cin>>A>>B>>x;
        x--;
        e[i].eb(ii{A,i+1});
        e[i].eb(ii{B,x});
    }

    vi dist(n,INF);
    priority_queue<ii, vector<ii> , greater<>> pq;
    pq.push(ii{0,0});
    while(!pq.empty()){
        const auto tp=pq.top();
        pq.pop();
        const lli u=tp.Y,d=tp.X;
        if(dist[u]<=d)
            continue;
        dist[u]=d;
        for(auto x:e[u])
            pq.push(ii{d+x.X,x.Y});
    }
    cout<<dist[n-1]<<endl;
}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
