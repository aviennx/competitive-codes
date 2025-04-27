#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 
map<int, long long> mp;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    mp.clear();
    for(int& i : arr)
        cin >> i;
    for (int i = 0; i < n; i++)
        mp[arr[i]+i+1] += 1;
    vector<int> ans;
    for(int i=0; i < n;i++){
        if(mp.empty())
            break;
        auto [val, cnt] = *--mp.end();
        mp.erase(--mp.end());
        ans.push_back(val);
        if(cnt > 1)
            mp[val-1]+=cnt-1;
    }
    for(int i : ans)
        cout << i << " ";
    cout<<endl;

}


int main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
