#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, m , k;
    cin >> n >> m >> k;
    vector<int> ans;
    int curr = n;
    if(k <= n){
        while(curr >= k){
            ans.push_back(curr);
            curr--;
        }
    }
    int rem = curr;
    if(curr != 0){
        while(curr > m){
            ans.push_back(curr);
            curr--;
        }
    }
    rem = 1;
    if(curr != 0){
        while(rem <= curr){
            ans.push_back(rem);
            rem++;
        }
    }
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
