#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define pii pair <int, int>
#define int long long
const int N = 2e5 + 5;


int gcd(int x, int y){
    if (x < y) swap(x, y);
    while (x > y && y != 0){
        x %= y;
        swap(x, y);
    }
    return x;
}

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int mn = INT_MAX, mx = -1;
    for(int i : arr){
        mn = min(mn, i);
        mx = max(mx, i);
    }
    //sort(arr.begin(), arr.end());
    int ans = mx - mn;
    map<int,int> mp;
    int com = gcd(a , b);
    //cout << com << " -- \n";
    for(int i : arr)
        mp[i % com]++;
    bool check = false;
    vector<pair<int,int>> vals;
    for(auto [v, cnt] : mp)
        vals.push_back({v , cnt});
    sort(vals.begin(), vals.end());
    int sz = vals.size();
    ans = min(ans, vals.back().first - vals[0].first);
    for(int i = 0; i < sz; i++){
        auto [v, c1] = vals[i];
        if(c1 >= 2){
            check = true;
            ans = min(ans, com);
        }
        c1 %= 2;
        if(i == sz - 1)
            break;
        auto [v2, c2] = vals[i + 1];
        //cout << v << " " << v2 << '\n';
        ans = min(ans, v - v2 + com);
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

