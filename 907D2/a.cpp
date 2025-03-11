#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr){
        cin >> i;
    }
    int upto = 1;
    int prev = 0;
    bool flag = true;
    while(prev < n){
        //cout << prev << " " << upto - 1 << '\n';
        for(int i = prev; i < min(n, upto); i++){
            if(i + 1 < min(n, upto) && arr[i + 1] < arr[i]){
                //cout << i << " makes false\n";
                flag = false;
            }
        }
        prev = upto;
        upto *= 2;
    }
    if(flag)
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
