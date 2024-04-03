#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr = {n};
    int ans = 0;
    priority_queue<int> pq;
    pq.push(n);
    while (pq.size()) {
        int curr = pq.top();
        pq.pop();
        if (curr == 1)
            continue;
        ans++;
        int cnt = min(k, curr);
        cnt--;
        pq.push(curr - cnt);
    }
    cout << ans << endl;
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
