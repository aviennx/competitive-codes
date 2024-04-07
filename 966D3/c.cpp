#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, m;
    cin >> n ;
    vector<int> prev(n, -1);
     vector<int> prev1(n, -1);
    vector<int> arr(n);
    unordered_map<int,int> mp;
    for(int& i : arr)
        cin >> i;
    for(int i = 0; i < n; i++){
        if(mp.count(arr[i])){
            prev[i] = mp[arr[i]];
        }
        mp[arr[i]] = i;
    }
    cin >> m;
    while(m--){
        string s;
        cin >> s;
        if(s.size() != n){
            cout << "NO\n";
            continue;
        }
        unordered_map<char,int> mp2;
       
        for(int i = 0; i < n; i++){
            prev1[i] = -1;
            if(mp2.count(s[i]))
                prev1[i] = mp2[s[i]];
            mp2[s[i]] = i;
        }
        bool flag = true;
        for(int i = 0; i < s.size(); i++){
            //cout << prev1[i] << " - " << prev[i] << '\n';
            if(prev1[i] != prev[i]){
                flag = false;
            }
        }
        yesno(flag);
        continue;
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

