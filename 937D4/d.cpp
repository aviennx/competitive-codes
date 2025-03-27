#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int x;
    cin >> x;
    string s = to_string(x);
    
    if(count(s.begin(), s.end(), '0') + count(s.begin(), s.end(), '1') == (int)s.size()){
        yesno(1);
        return;
    }
while(x > 1){
    int cnt = 0;
    vector<int> factors;
    bool found = false;
    for(int i = 1 ; i <= sqrt(x); i++){
        if(x % i == 0 && i != x / i){
            factors.push_back(i);
            factors.push_back(x / i);
        }else if(x % i == 0)
            factors.push_back(i);
    }
    sort(factors.rbegin(), factors.rend());
    factors.pop_back();
    for(int f : factors){
        string a = to_string(f);
        if(count(a.begin(), a.end(), '0') + count(a.begin(), a.end(), '1') == (int)a.size()){
            x /= f;
            found = true;
            break;
        }
    }
    if(!found){
        yesno(0);
        return;
    }
}
    yesno(1);

   


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
