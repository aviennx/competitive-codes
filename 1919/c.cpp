#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n ;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int a = INT_MAX, b = INT_MAX;
    int ans = 0;
    for(int i : arr){
        if( b > a)
            swap(a, b);
        if(i > a){
            b = i;
            ans ++;
        }else if(i <= b){
            b = i;
        }else{
            a = i;
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
