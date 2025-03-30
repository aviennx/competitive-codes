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
    string s;
    cin >> s;
    set<char> st;
    vector<char> arr;
    for(auto c : s)
        st.insert(c);
    for(auto c : st)
        arr.push_back(c);
    int z = arr.size();
    map<char, char> mp;
    for(int i = 0; i < z; i++){
        mp[arr[i]] = arr[z - 1 - i];
    }
    string ans = "";
    for(auto c : s){
        ans += mp[c];
    }
    cout << ans << '\n';
   


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
