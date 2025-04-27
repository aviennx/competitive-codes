#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    unordered_map<string,int> mp;
    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        mp[x]++;
    }
    vector<pair<int,string>> arr;
    for(auto[s, cnt] : mp)
        arr.push_back({cnt , s});
    sort(arr.rbegin() , arr.rend());
    if(arr[0].first > n / 2)
        cout << arr[0].second << '\n';
    else
        cout <<"uh-oh\n";
    


}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
   int t = 1;
   // cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
