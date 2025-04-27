#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    cin >> n;
    int sz = n;
    vector<int> arr(n, -1);
    int start = 0;
    if(n % 2 == 0)
        start = 1;
    while(start < sz){
        arr[start] = n;
        n--;
        start += 2;
    }
    start = sz -2;
    while(start >= 0){
        arr[start] = n;
        n --;
        start -= 2;
    }
    for(int i : arr)
        cout << i << " ";
    cout << endl;


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
