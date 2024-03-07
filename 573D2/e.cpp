#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;
bool winone(vector<int>& arr, vector<int>& pref, int k){    
    int n = arr.size() - 1;
    for(int i = 1; i <= n - k + 1; i++){
        int ones = pref[i - 1] + pref[n] - pref[i + k - 1];
        if(ones == 0 || ones + k == n)
            return true;
    }
    return false;
}   
bool wintwo(vector<int>& arr, vector<int>& pref, int k){
    int n = arr.size() - 1;
    if(k*2<n||k==1)
        return false;
    int len=n- k - 1;
    for(int i=2;i<=len;++i){
        if(arr[i]!=arr[i-1]||arr[n-i+1]!=arr[n-i+2])
            return false;
    }
    return true;
}




void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> arr(n + 1), pref(n + 1, 0);
    for(int i = 0; i < n; i++){
        arr[i + 1] = s[i] == '1';
        pref[i + 1] = pref[i];
        pref[i + 1] += s[i] == '1';
    } 
    if(winone(arr, pref, k))
        cout << "tokitsukaze\n";
    else if(wintwo(arr, pref, k))
        cout << "quailty\n";
    else
        cout << "once again\n";
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
