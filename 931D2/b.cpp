#include<bits/stdc++.h>
using namespace std;


const int N = 2e5 + 5;


void solve(){
    int n;
    cin >> n;
    
    vector<int> arr = {0, 1 , 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3};
    int k = n / 15;
    int rem = n % 15;
    int ans = k + arr[rem];
    if(k >= 1){
        rem += 15;
        int k2 = rem / 10;
        rem %= 10;
        ans = min(ans , k - 1 + k2 + arr[rem]);
    }
    

    cout << ans << '\n';

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
