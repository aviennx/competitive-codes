#include<bits/stdc++.h>
using namespace std;

#define int long long  

#define ar array
#define ll long long 
const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l =0, r= n-1;
    while(l < n && s[l] == 'W')
        l++;
    while(l<r && s[r] =='W')
        r--;
    if(l == n )
        cout << 0 << endl;
    else{
        cout << r-l+1 << endl;
    }

}


int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
