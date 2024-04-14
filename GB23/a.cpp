#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 
#define int long long
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int v = 1;
    for(int& i : arr){
        cin >> i;
        v *= i;
    }
    if(v == 0 || v > 2023 || (2023 / v) * v != 2023 || (2023 / v > 0 && k == 0) ){
        cout << "NO\n";
        return;
    }
    int need = 2023 / v;
    cout << "YES\n";
    cout << need << " ";
    for(int i = 1; i < k; i++)
        cout << 1 << " ";
    cout << '\n';


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
