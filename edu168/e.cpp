#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n , k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    int cnt1 = 0, cnt0 = 0;
    int same = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == t[i]){
            same++;
            continue;
        }
        //cout << cnt0 << "; " ;
        if(s[i] == '1'){
            cnt1++;
        }else
            cnt0++;
    }
    cout << cnt0 << " " << cnt1 << " ";
    if(cnt1 != cnt0 || k < cnt1){
        cout << "lll NO\n";
        return;
    }
    k -= cnt1;
    
    if(same >= 2 || k % 2 == 0 || (same && cnt1) || (same && cnt0))
        cout << "YES\n";
    else 
        cout << "NO\n";
    
    
        
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

