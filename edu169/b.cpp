#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int arr1[2], arr2[2];
    cin >> arr1[0] >> arr1[1] >> arr2[0] >> arr2[1];
    if(arr1[0] > arr2[0])
        swap(arr1, arr2);
    //out << arr2[0] << '\n';
    if(arr1[1] < arr2[0]){
        cout << 1 << '\n';
        return;
    }
    int l = max(arr1[0] ,arr2[0]);
    int r = min(arr1[1], arr2[1]);
    int d = r - l;
    //cout << l << " " << r << '\n';
    if(d < 0){
        cout << 1 << '\n';
        return;
    }
    if(d == 0){
        cout << 2 << '\n';
        return;
    }
    int ans = d;
    if(min(arr1[0], arr2[0]) < l)
        ans++;
    if(max(arr1[1], arr2[1]) > r)
        ans++;
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
