#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(m);
    for(int& i : arr)
        cin >> i;
    sort(arr.begin() , arr.end());
    int ops = 0;
    int ans = 0;
    int curr_index = 0;
    int sum = 0;
    while(curr_index < m){
        int r = sum + ((arr[curr_index] - sum - 1) / k + 1) * k - 1;
        while(curr_index < m && arr[curr_index] - 1 <= r){
            sum++;
            curr_index++;
        }
        ans++;
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
