#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    int cnt = -1;
    vector<int> a(n + 1, 0);
    for(int i = x + 1 ; i <= n ; i++){
        a[i] = cnt;
        if(cnt == -1)
            cnt += 2;
        else
            cnt -= 2;
    }
    cnt = -1;
    for(int i = y - 1 ; i >= 1 ; i--){
        a[i] = cnt;
        if(cnt == -1)
            cnt += 2;
        else
            cnt -= 2;
    }
    vector<int> check(n, 0);
    vector<int> pref(n, 0);
    for(int i = 0; i < n; i += 2){
        check[i] = 1;
        if(i + 1< n)
            check[i + 1] = -1;
        if(i)
            pref[i] = pref[ i - 1];
        pref[i] += check[i];
    }
    for(int i = y ; i <= x ; i++)
        a[i] = 1;
    for(int i = 1 ; i <= n ; i++)
        cout << a[i] << " ";
    cout << "\n";
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
