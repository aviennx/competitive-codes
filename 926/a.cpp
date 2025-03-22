#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;

    sort(arr.begin(), arr.end());
    if(n  == 1)
        cout << 0 << endl;
    else 
        cout << arr.back() - arr[0] << endl; 

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
