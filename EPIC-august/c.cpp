#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<array<int,4>> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i][0] >> c[i][1];
    }
    int x1, y1, x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int closest1 = LLONG_MAX;
    int closest2 = LLONG_MAX;
    for(int i = 0 ; i < n; i++){
        int d = (c[i][0] - x1) * (c[i][0] - x1) + (c[i][1] - y1) * (c[i][1] - y1);
        c[i][2] = d;
        closest1 = min(closest1, d);
        d = (c[i][0] - x2) * (c[i][0] - x2) + (c[i][1] - y2) * (c[i][1] - y2);
        c[i][3] = d;
        closest2 = min(closest2, d);
    }
    int base = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    if(closest2 <= base){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
