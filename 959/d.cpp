#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

//const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    vector<pair<int,int>> ans;
    vector<int> curr(n , 1);
    for(int i = n - 1; i >= 1; i--){
        vector<int> here(n, -1);
        for(int j = 0; j < n; j++){
            if(curr[j] == 0)
                continue;
            int rem = arr[j] % i;
            if(here[rem] != -1){
                ans.push_back({j + 1, here[rem] + 1});
                curr[j] = 0;
                break;
            }
            here[rem] = j;
        }
    }
    if(ans.size() != n - 1)
        cout << "NO\n";
    else{
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        for(auto [a, b] : ans)
            cout << a << " " << b << '\n';
    }
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