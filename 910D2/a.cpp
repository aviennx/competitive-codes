#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int b = 0;
    for(char c: s)
        if(c == 'B')
            b++;
    if(b > k){
        int del = b - k;
        for(int i = 1; i <= n; i++){
            if(s[i - 1] == 'B')
                del--;
            if(del == 0){
                cout << 1 << '\n';
                cout << i << " A\n";
                return; 
            }
        }
    }else if(b < k){
        int del = k - b;
        for(int i = 1; i <= n; i++){
            if(s[i - 1] == 'A')
                del--;
            if(del == 0){
                cout << 1 << '\n';
                cout << i << " B\n";
                return; 
            }
        }
    }else{
        cout << 0 << '\n';
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
