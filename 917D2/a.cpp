#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int neg = 0, zero = 0;
    int cnt = 0;
    int rand_neg = 0, rand_pos = 0;
    for(int& i : arr){
        cin >> i;
        zero += (i == 0);
        neg += (i < 0);
        if(i < 0)
            rand_neg = cnt;
        if(i > 0)
            rand_pos = cnt;
        cnt++;
    }
    if(zero || (neg && neg % 2)){
        cout << 0 << '\n';
        return;
    }
    if(neg && neg % 2 == 0){
        cout << 1 << '\n';
        cout << rand_neg + 1 << " " << 0 << '\n';
        return;
    }
    cout << 1 << '\n';
        cout << rand_pos + 1 << " " << 0 << '\n';
        return;





   


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
