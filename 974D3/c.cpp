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
    vector<int> arr(n + 1, 0);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int mid = (n % 2 == 0) ? n / 2 + 1 : (n + 1) / 2;
    int sum = accumulate(arr.begin(), arr.end(), 0ll);
    if(n <= 2){
        cout << -1 << '\n';
        return;
    }
    cout << max(0ll,2 * n * arr[mid] - sum + 1 )<< '\n';
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
