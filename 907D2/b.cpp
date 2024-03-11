#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    vector<int> set_bits;
    int mxbit = 32;
    while(q--){
        int bit;
        cin >> bit;
        if(bit > mxbit)
            continue;
        set_bits.push_back(bit - 1);
        mxbit = bit - 1;
    }
    for(int& val : arr){
        int max_set = 0;
        for(int i = 0; i < 31; i++){
            if((val >> i) & 1)
                break;
            max_set++;
        }
        for(int j : set_bits){
            if(j < max_set)
                val += (1 << j);
        }
    }
    for(int i : arr)
        cout << i << " ";
    cout << '\n';


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
