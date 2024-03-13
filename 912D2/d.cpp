#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n ,q;
    cin >> n >> q;
    vector<int> arr2(n);
    for(int& i : arr2)
        cin >> i;
    while(q--){
        int k;
        int ans = 0;
        vector<int> arr = arr2;
        cin >> k;
        for(int bit = 60; bit >= 0; bit--){
            bool flag = false;
            int cost = 0;
            for(int i : arr){
                if((i >> bit) & 1ll)
                    continue;
                cost += (1ll << bit) - (i % (1ll << bit));
                if(cost > k){
                    flag = true;
                    break;
                }
            }
            if(flag)
                continue;
            if(cost <= k){
                ans += (1ll << bit);
                k -= cost;
                for(int& i : arr){
                    if((i >> bit) & 1)
                        continue;
                    i = i + (1ll << bit) - (i % (1ll << bit));
                }
            }
        }
        cout << ans << '\n';
    }
   


}


int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
