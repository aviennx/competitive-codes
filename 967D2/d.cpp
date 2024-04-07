#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")


void solve(){
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    int l = 1, r = 0;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    map<int,vector<int>> index;
    unordered_map<int,int> mp;
    for(int i = 1; i <= n; i++){
        index[arr[i]].push_back(i);
    }
    priority_queue<int> pqv;
    set<int> curr, pqi;
    for(auto [v, vec] : index){
        pqi.insert(vec.back());
        mp[v] = vec.back();
    }
    int tp = 1;
    vector<int> ans;

    int sz = pqi.size();
    //cout << sz << '\n';
    for(int i = 1; i <= sz; i++){
        //cout << i << " : " << '\n';
        tp = *pqi.begin();
        bool done = false;
        while(r < tp){
            if(mp.count(arr[r + 1])){
                curr.insert(arr[r + 1]);
                //done = true;
                r++;
            }else
                r++;
        }
        int hi = *curr.rbegin();
        int lo = *curr.begin();
        int check = (i % 2  ) ? hi : lo;
        while(arr[l] != check){
                auto it = curr.find(arr[l]);
                curr.erase(it);
            l++;
        }
        if(curr.find(check) != curr.end())
            curr.erase(check);
        ans.push_back(check);
        //cout << check << " " << i << "\n";
        pqi.erase(mp[check]);
        l++;
        mp.erase(check);
        //cout << i << " : " << '\n';
    }
    cout << sz << '\n';
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
