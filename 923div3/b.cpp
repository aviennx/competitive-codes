#include<bits/stdc++.h>
using namespace std;

#define int long long  

#define ar array
#define ll long long 

const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;


void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    unordered_map<int,vector<char>> prev;

    string ans = "";

    int curr_char = 'a';
    for(int i =0 ;i <n;i++){

        if(arr[i] == 0){
            ans += curr_char;
            prev[1].push_back(curr_char);
            curr_char++;   
            continue;
        }

        int need = arr[i];
        char c = prev[need].back();
        prev[need].pop_back();
        prev[need+1].push_back(c);
        ans += c;
    }
    cout << ans << endl;
}


int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
