#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    bool poss = true;
    for(int i = 1; i < n - 1; i++){
        int ops = min(arr[i - 1], arr[i + 1]);
        arr[i - 1] -= ops;
        arr[i + 1] -= ops;
        arr[i] -= 2 * ops;
        if(arr[i] < 0 || arr[i + 1] < 0 || arr[i - 1] != 0){
            poss = false;
            break;
        }
    }
    if(!poss || arr[n - 1] != 0)
        cout << "NO\n";
    else
        cout << "YES\n";

}


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
