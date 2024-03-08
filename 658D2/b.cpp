#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "First\n" : "Second\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i: arr)
        cin >> i;
    int ones = 0 ;
 
    for(auto &x : arr){
        if(x == 1)
            ones ++ ;
    }
    if(n == 1 || ones == 0){
        cout << "First" << endl ;
        return ;
    }
    if (ones == n ){
        cout << (n&1?"First":"Second" ) << endl ;
        return ;
    }
 
    bool first = false;
    for(int i = 0 ; i < n; i++){
        if(arr[i] == 1){
            first ^= 1 ;
        }
        else{
            break ;
        }
    }
    cout << (first?"Second" : "First") << endl ;

}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
