#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
const int N = 2e5 + 5;
int n, m, a[N], b[N];
vector <int> adj[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i++){
        int l = 0;
        cin >> l;
        for(int j = 0; j < l; j++){
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }
    int mx = 0;
    for(auto& v : arr){
        set<int> st;
        for(int& i : v)
            st.insert(i);
        int low = 0;
        bool brk = false;
        while(st.count(low))
            low++;
        if(st.count(low + 1)){
            brk = true;
            while(st.count(low + 1)){
                low++;
                if(low == v.size())
                    break;
            }
        }
        //cout << low << " - ";
        mx = max(mx, low + 1);
    }
    cout << mx << " ";
    int ans = mx * (m + 1);
    if (mx >= m){
        cout << ans << '\n';
        return;
    }
    int mid =( m + mx + 1 );
    ans = mx * mx + (m - mx) * mid / 2 + mx;
    cout << ans << '\n';
    return;
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
