#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int k , x , a;
    cin >> k >> x >> a;
    if( a <= x){
        cout << "No\n";
        return;
    }
    if(k > x + 1){
        cout << "Yes\n";
        return;
    }
    long long curr_bet = 0;

    for(int i = 0; i <= x; i++){
        int need =  curr_bet / (k - 1) + 1;
        curr_bet += need;
        if(curr_bet > a){
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";


}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
