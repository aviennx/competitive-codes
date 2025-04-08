#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    inp(arr);
    int ans = 0; 
    for(int fact = 1; fact <= n ; fact++){
        if(n % fact == 0){
            int g = 0 ; 
            for(int i = 0 ; i + fact< n; i++ ){
                g = __gcd( g, abs (arr[i] - arr[i + fact] ) );
            }
            ans += g != 1;
        }
    }
    cout << ans << endl;


}


int main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
