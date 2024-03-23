#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int actual_index = 1;
    for(int i = 0; i < n; i++)
        if(arr[i] == m)
            actual_index = i + 1;
    int l = 0, r = n;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(arr[mid] <= m)
            l = mid;
        else
            r = mid;
    }
    if(arr[l] == m)
        cout << "0\n";
    else{
        cout << 1 << '\n';
        cout << l + 1 << " " << actual_index << '\n';
    }
   


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
