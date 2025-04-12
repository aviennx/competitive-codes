#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

int mn[N], mx[N], arr[N];
void solve(){
    int n;
    cin >> n;
    mn[0] = n + 1, mx[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 0; i <= n + 1; i++ )
        mn[i] = n + 1, mx[i] = 0;
    for(int i = 1; i <= n; i++){
        mn[arr[i]] = min(mn[arr[i]], i), mx[arr[i]] = max(mx[arr[i]], i);
    }
    int l = n + 1, r = 0;
    for(int i = 1; i <= n; i++){
        l = min(l, mn[i]);
        r = max(r, mx[i]);
        if(r - l + 1 > i){
            cout << 0 << '\n';
            return;
        }
    }
    l = 1, r = n;
    for(int i = 1; i <= n; i++){
        l = max(l, i - arr[i] + 1);
        r = min(r, i + arr[i] - 1);
    }
    cout << max(0ll, r - l + 1) << '\n';
}


int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
