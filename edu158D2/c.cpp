#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    sort(arr.begin() ,arr.end());
    int l = arr[0], r = arr.back();
    vector<int> ans;
    while(l != r){
        int v = l % 2;
        ans.push_back(v);
        l = (l + v ) / 2;
        r = ( r + v) / 2;
    }
    cout << (int)ans.size() << '\n';
    if((int)ans.size() <= n)
        for(int i : ans)
            cout << i << " ";
    else
        return;
    if(!ans.empty())
        cout << '\n';
   


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
