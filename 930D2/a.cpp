#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    cin >> n;
    int val = 1;
    while(val < n){
        val <<= 1;
    }
    if(val > n)
        cout << (val >> 1) << endl;
    else
        cout << val << endl;


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
