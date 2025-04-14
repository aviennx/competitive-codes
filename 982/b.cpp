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
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int curr = 0;
        int x = arr[i];
        for(int j = 0; j < n; j++){
            if(arr[j] == arr[i])
                continue;
            if(j < i)
                curr++;
            else if(j > i && arr[j] > arr[i])
                curr++;
        }
        ans = min(ans, curr);
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
