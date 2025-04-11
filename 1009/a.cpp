#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n , m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for(int& i : arr1)
        cin >> i;
    for(int& i : arr2)
        cin >> i;

    int i = 0 , j = 0;
    int ans = 0;
    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            j++;
            ans ++;
        }
        i++;
    }

    cout << ans << endl;

}


int main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    //cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
