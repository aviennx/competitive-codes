#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> e;
vector<int> dp;
vector<int> max_dp;
vector<int> ct, ct2;
vector<bool> vis;

void dfs(int u) {
	vis[u] = true;
	max_dp[u] = dp[u];
	for(int v : e[u]) {
		if(vis[v]) continue;
		dp[v] = dp[u] + 1;
		dfs(v);
		max_dp[u] = max(max_dp[u], max_dp[v]);
	}
}

int main() {
	freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t; cin >> t;
    while(t--) {
    	int n; cin >> n;
    	e.resize(n + 3);
    	dp.resize(n + 3, 0);
    	max_dp.resize(n + 3, 0);
    	ct.resize(n + 3, 0);
    	ct2.resize(n + 3, 0);
    	vis.resize(n + 3, 0);

    	for(int i = 1; i <= n; i++) {
    		e[i].clear();
    		vis[i] = dp[i] = max_dp[i] = ct[i] = ct2[i] = 0;
    	}

    	for(int i = 1; i < n; i++) {
    		int a, b; cin >> a >> b;
    		e[a].push_back(b);
    		e[b].push_back(a);
    	}

    	dfs(1);
    	for(int i = 1; i <= n; i++) {
    		++ct[dp[i]];
    		++ct2[max_dp[i]];
    		//out << dp[i] << " " << max_dp[i];
    	}
    	//cout << '\n';


    	int res = 1e9;
    	int a = 0;
    	int b = 0;
    	for(int i = 1; i <= n; i++) b += ct[i];
    	for(int i = 1; i <= n; i++) {
    		b -= ct[i];
    		res = min(res, a + b);
    		a += ct2[i];
    	}
    	cout << res << '\n';
    }
}
