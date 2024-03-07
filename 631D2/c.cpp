#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    
    for(int i = 0; i < m; i++){
        cin >> arr[i];
        if(arr[i] + i > n){
            cout << -1 << '\n';
            return;
        }
    }

    vector<int> suff(m, 0);
    for(int i = m - 1; i >= 0; i--){
        suff[i] = arr[i];
        if(i < m - 1)
            suff[i] += suff[i + 1];
    }
    if(suff[0] < n){
        cout << -1 << '\n';
        return;
    }



    for(int i = 0; i < m; i++){
        cout << max(i + 1, n - suff[i] + 1) << " ";
    }
    cout << '\n';
}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
