#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n , k , m;
    cin >> n >> k >> m ;
    string s;
    cin >> s;
    //bool flag = true;

    bool present[26] = {};
    memset(present, false, sizeof(present));
    int count = 0;
    string ans = "";

    for(char c : s){
        if((int)ans.size() >= n)
            break;
        if(!present[c-'a'])
            count++;
        present[c - 'a'] = true;

        if(count >= k){
            memset(present, false, sizeof(present));
            count = 0 ;
            ans += c;
        }
    }

    if((int)ans.size() >= n){
        cout << "YES" << endl;
        return ;
    }

    int need = n - ans.size();

    for(int i = 0 ; i < k ; i++){
        if(present[i] == false){
            string add = string (need, 'a' + i);
            ans += add;
            break;
        }
    }
    cout <<"NO" << endl;
    cout << ans << endl;
    return ;


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
