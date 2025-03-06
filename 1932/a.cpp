#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int i = 0;
    while(i < n){
        if(s[i] == '*')
            break;
        else if(s[i] == '@')
            ans++;
        if(i + 1 < n && s[i + 1] == '*')
            i += 2;
        else
            i++;
        
    }
    cout << ans << endl;

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
