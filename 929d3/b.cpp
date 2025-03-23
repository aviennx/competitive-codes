#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define ll     long long

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int rem[3] = {};
    ll sum = 0;
    for(int& i : arr){
        cin >> i;
        sum += i;
        rem[i % 3] ++;
    }
    if(sum % 3 == 0)
        cout << 0 << endl;
    else if(sum % 3 == 2)
        cout << 1 << endl;
    else{
        if(rem[1] != 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }

}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
