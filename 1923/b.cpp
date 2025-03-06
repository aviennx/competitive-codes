#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int x , n ;
    cin >> x >> n;
    //int rem = 0;
    //int base =0 ;
    int ans = 1;
    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            if(n <= x/i){
                ans = max(ans , i);
            }
            if(n <= i){
                ans = max(ans, x/i);
            }
        }
    }
    cout << ans << endl;
}


int main(){
   // freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
