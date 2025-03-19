#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n , k ;
    cin >> n >> k;
    unordered_map<int,set<int>> adj;
    vector<int> indeg(n+1,0);
    for(int i = 0 ; i < k; i++){
        int prev = 0, next = 0;
        for(int i =0; i < n; i++){
            if(i == 0){
                cin >> next;
                continue;
            }
            cin >> next;
            if(!adj[prev].count(next)){
                indeg[next]++;
                adj[prev].insert(next);
            }
            prev = next;
        }
    }
    int count = n + 1;
    queue<int> q;
    for(int i = 0; i <= n; i++)
        if(indeg[i] == 0){
            q.push(i);
    }
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int curr = q.front();
            q.pop();
            count--;
            for(int next : adj[curr]){
                indeg[next]--;
                if(indeg[next] == 0)
                    q.push(next);
            }
        }
    }
    if(count == 0)
        cout << "YES\n";
    else
        cout <<"NO\n";

}


int main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
