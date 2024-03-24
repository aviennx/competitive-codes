#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define ll long long
const int mod = 1e9 + 7;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

   
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for(int& i : arr)
        cin >> i;
    if(primes.find(k) == primes.end()){
        cout << 0 << '\n';
        return;
    }
    


    
   


}

  xcvghbjn
int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
