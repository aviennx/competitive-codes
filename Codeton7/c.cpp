#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), ids(n);
    for(int& i : a)
        cin >> i;
    for(int& i : b)
        cin >> i;
    iota(ids.begin() ,ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    sort(b.begin() ,b.end());
    vector<int> ans(n);
    
    for(int i = 0; i < x; i++)
        ans[ids[n - x + i]] = b[i];
    for(int i = x; i < n; i++)
        ans[ids[i - x]] = b[i];
    for(int i = 0 ; i < n; i++)
        if(a[i] > ans[i])
            x--;
    if(x == 0){
        yesno(1);
        for(int i : ans)
            cout << i << " ";
        cout << '\n';
    }else
        yesno(0);


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
