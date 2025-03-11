#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int,int> cnt;
    for(int& i : arr){
        cin >> i;
        cnt[i]++;
    }
    if(cnt.size() > 2){
        yesno(0);
        return;
    }
    if(cnt.size() == 1){
        yesno(1);
    return;
}
    if(n % 2 && (cnt[arr[0]] == n / 2 || cnt[arr[0]] == n / 2 + 1 ))
        yesno(1);
    else if(n % 2 == 0 && cnt[arr[0]] == n / 2)
        yesno(1);
    else
        yesno(0);
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
