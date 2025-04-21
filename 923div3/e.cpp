#include<bits/stdc++.h>
using namespace std;

#define int long long  

#define ar array
#define ll long long 




void solve(){
    int n , k;
    cin >> n >> k;
    vector<int> ans(n);

    //int count = (n+k-1)/k;
    int low = 1, high = n;
    int which = 0;
    for(int i =0; i <k ;i++){
        for(int j = i ; j <n ; j += k){
            if(which == 0){
                ans[j] = low;
                low ++;
            }else{
                ans[j] = high;
                high--;
            }
        }
        which ^= 1;
    }
    for(int i : ans)
        cout << i << " " ;
    cout << endl;

}


int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
