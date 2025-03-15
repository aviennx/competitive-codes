#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    bool issorted = true;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i && arr[i] < arr[i - 1])
            issorted = false;
    }
    if(k == 1 && issorted == false)
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
