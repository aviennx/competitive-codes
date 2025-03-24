#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n, k;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
    cin >> n >> k;
    it = std::find(primes.begin(), 
                 primes.end(), k);

    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;

    if(it == primes.end()){
        cout << "0\n";
        return;
    }

    vector<vector<int>> adj(primes.size());

    for(int i = 0; i < n; i++){
        
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
