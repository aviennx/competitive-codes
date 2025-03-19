#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    map<int,map<int,int>> mp;
    long long ans =0;
    for(int& i : arr){
        int d1 =( x - i % x ) % x;
        int d2 = (i % y);
        ans += mp[d1][d2];
        mp[i % x][i % y]++;
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
