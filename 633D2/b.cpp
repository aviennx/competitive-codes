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
    sort(arr.begin() ,arr.end());
    vector<int> ans;
    int l = 0, r = n - 1;
    int turn = 1;
    for(int i = 0; i < n; i++){
        if(turn)
            ans.push_back(arr[r--]);
        else
            ans.push_back(arr[l++]);
        turn ^= 1;
    }   
    reverse(ans.begin(), ans.end());
    for(int i : ans)
        cout << i << " ";
    cout << '\n';


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
