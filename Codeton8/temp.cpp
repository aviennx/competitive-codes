#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")


void solve(){
    int m, n;
    cin >> m >> n;
    vector<int> cntset(m + 2, 0), pref(m + 2, 0);
    vector<pair<int,int>> vp;
    int ans = 0;
    for(int i = 0 ; i  < n ; i++){
        cin >> vp[i].first;
    }
    for(int i = 0 ; i  < n ; i++){
        cin >> vp[i].second;
    }
    for(int i = 0; i < n;i ++){
        int start , end;
        start = vp[i].first, end = vp[i].second;
        if(start <= end){
            if(2 * (end - start) >= m){
                ans++;
                continue;
            }
            cntset[end]--;
            cntset[start]++;
        }else{
            if(2 * (m + end - start) >= m){
                ans++;
                continue;
            }
            cntset[end]--;
            cntset[1]++;
            cntset[start]++;
        }
    }
    for(int i = 1; i <= m; i++){
        cntset[i] += cntset[i - 1];
    }
    int ans1 = 0;

    for(int i = 1; i <= m; i++){
        int j = i + m / 2;
        if(j > m)
            break;
        ans1 = max(ans1, cntset[i] + cntset[j]);
        if(m % 2)
            ans1 = max(ans1, cntset[i] + cntset[j % m + 1]);
    }
    cout << ans + ans1 << '\n';
    
}

int32_t main() {
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;

}
