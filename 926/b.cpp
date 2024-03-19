#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n , k;
    cin >> n >> k;
    int ans = 0;
    if(k > 4 * n - 4){
        ans = 2 * n - 2 + (k - (4 * n - 4));
    }else{
        ans = (k + 1 )/ 2;
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
