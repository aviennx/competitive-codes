#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int a, b;
    cin >> a >> b;
    vector<int> arr;
    for(int i = 0; i < a; i++)
        arr.push_back(1);
    for(int i = 0; i < b; i++)
        arr.push_back(2);
    int tot = (1 << (a + b));
    bool ans = false;
    for(int i = 0; i < tot; i++){
        int sum = 0;
        for(int j = 0; j < (a + b); j++){
            if((i >> j) & 1)
                sum += arr[j];
            else
                sum -= arr[j];
        }
        if(sum == 0)
            ans = 1;
    }
    yesno(ans);
   


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
