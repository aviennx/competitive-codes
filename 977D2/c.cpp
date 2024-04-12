#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YA\n" : "TIDAK\n")

const int N = 2e5 + 5;

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> arr(n), b(m);
    for(int& i : arr){
        cin >> i;
        i--;
    }
    for(int& i : b){
        cin >> i;
        i--;
    }
    reverse(arr.begin(), arr.end());
    set<int> st;
    bool ans = 1;
    for(int i = 0; i < m; i++){
        int need = b[i];
        int have = -1;
        if(!arr.empty())
            have = arr.back();
        if(have == need){
            st.insert(need);
            arr.pop_back();
            continue;
        }
        if(st.count(need)){
            continue;
        }
        else{
            ans = false;
        }
    }
    yesno(ans);


   


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
