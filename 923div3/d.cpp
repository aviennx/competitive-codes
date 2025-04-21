#include<bits/stdc++.h>
using namespace std;

#define int long long  

#define ar array
#define ll long long 

const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;


void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int q;
    cin >> q;

    vector<int> prev(n);
    prev[0] = -1;
    for(int i = 1; i <n;i ++){
        if(arr[i] != arr[i-1])
            prev[i] = i-1;
        else
            prev[i] = prev[i-1];
        //cout << prev[i] <<" ";
    }

    while(q--){
        int l , r;
        cin >> l >> r;
        l--,r--;
        if(prev[r] < l){
            cout << -1 <<" " << -1 << endl;
            continue;
        }
        int a = arr[prev[r]];
        int b = arr[r];

        if(a!=b){
            cout << r +1 <<" " << prev[r] + 1<< endl;
        }else{
            cout << -1 <<" " << -1 << endl;
        }
    }

    return ;



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
