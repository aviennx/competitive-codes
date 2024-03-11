#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    int counter = 0;
    unordered_map<int,vector<int>> mp;
    vector<int> a(n);
    for(int& i : a){
        cin >> i;
        mp[i].push_back(counter);
        counter++;
    }
    int curr_done = 0;
    if(mp.size() < 2){
        cout << - 1 << '\n';
        return;
    }
    vector<int> ans(n, 1);
    for(auto [val , v] : mp){
        if(curr_done == 2)
            break;
        if(v.size() < 2)
            continue;
        v[0] = 1;
        for(int i  = 1 ; i < v.size(); i++)
            ans[v[i]] = curr_done + 2;
        curr_done++;
    }
    if(curr_done < 2){
        cout << -1 << '\n';
        return;
    }
    for(int i : ans)
        cout << i << " ";
    cout << '\n';

   


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
