#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int a = 0 , b= 0;
    for(auto c : s){
        if( c == '+' )
            a++;
        else
            b++;
    }
    int ans = abs(a-b);

    cout << ans << endl;

}


int main(){
    //reopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
