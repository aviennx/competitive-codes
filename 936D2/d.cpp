#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;
bool check(int x, int mask){
    return (mask | x ) == mask;
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int& i : a)
        cin >> i;
    vector<int> pref(n, 0);
    for(int i = 0;i < n; i++){
        if(i)
            pref[i] = pref[i - 1];
        pref[i] ^= a[i];
    }
    x++;
    int ans = -1;

    auto getV = [&](int mask)->int{
        if((pref[n - 1] & mask) != pref[n - 1])
            return -1;
        int count = 0;
        for(int i : pref)
            if((i & mask )== i)
                count++;
        return count;
    };

    for(int i = 30; i >= 0; i--){
        if((1 << i ) & x){
            int mask = (x ^ (1 << i)) | ((1 << i) - 1);
            ans = max(ans, getV(mask));
        }
    }
    cout << ans << '\n';
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


