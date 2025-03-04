#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

unordered_map<int,int> match;

void solve(){
    int n ;
    cin >> n;
    vector<int> arr1(n) , arr2(n);
    match.clear();

    for(int& i : arr1)
        cin >> i;
    for(int& i : arr2)
        cin >> i;

    for(int i = 0 ; i < n; i++){
        match[arr1[i]] = arr2[i];
    }

    sort(arr1.begin(), arr1.end());

    for(int i : arr1)
        cout << i << " ";
    cout << endl;

    for(int i : arr1)
        cout << match[i] << " ";

    cout << endl;
    return;



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
