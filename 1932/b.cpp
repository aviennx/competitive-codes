#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    long long time = 0;
    for(int i : arr){
        long long gap = time - i;
        if(gap <= 0){
            time = i + 1;
        }else{
            long long d = (gap + i - 1) / i;
            time = i  + i * d + 1;
        }
    }
    cout << time - 1 << endl;

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
