#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> count(n + 5);
    int def_mex = 0;
    for(int& i : arr){
        cin >> i;
        count[i]++;
        while(count[def_mex])
            def_mex++; 
    }
    int ans = def_mex;
    bool one_found = 0;
    for(int i = 0; i < def_mex; i++){
        if(count[i] == 1){
            if(one_found){
                ans = i;
                break;
            }
            else
                one_found = true;
        }
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
