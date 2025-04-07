#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int l;
    cin >> l;
    vector<int> arr(l);
    for(int& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    vector<int> grids;
    int ans = 0;
    vector<vector<int>> best(n, vector<int> (m, 0));
    int gd = n - k;
    int gr = m - k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            best[i][j] = 1;
            int u = i - (k - 1) + 1;
            if(u < 1)
                u = 1;
            int l = j - (k - 1) + 1;
            if(l < 1)
                l = 1;
            int d = min(i, gd );
            int r = min(j ,gr);
            best[i][j] = 1ll * (d + 2 - u) * (r + 2 - l);
            //cout << best[i][j] << " ";
        }
    }
    //set<int> st;
    vector<int> ch;
    for(int i = 0; i < n; i++){
        bool flag = false;
        for(int j = 0; j < m; j++){
            ch.push_back(best[i][j]);
            /*
            if(ch.size() >= l){
                flag = true;
                break;
            }*/
        }
        //if(flag)
        //    break;
    }
    sort(ch.rbegin(), ch.rend());
    for(int i = 0; i < l; i++){
        ans += arr[l - i - 1] * ch[i];
    }
    cout << ans << '\n';
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
