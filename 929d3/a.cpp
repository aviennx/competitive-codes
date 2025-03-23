#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 50;
#define ll     long long

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    ll ans = 0;
    for(int& i : arr){
        cin >> i;
        ans += abs(i);
    }
    cout << ans << endl;


}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
