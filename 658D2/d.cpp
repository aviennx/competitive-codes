#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int m;
    cin >> m;
    vector<int> arr(2 * m);
    for(int& i : arr)
        cin >> i;
    vector<int> set;
    int cnt = -1;
    int start = 0;
    for(int i : arr){
        if(i > start){
            if(cnt != -1)
                set.push_back(cnt);
            cnt = 1;
            start = i;
        }else{
            cnt++;
        }
    }
    set.push_back(cnt);
    int n = set.size();
    int sum = 2 * m;
    bool subset[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j]
                    = subset[i - 1][j]
                      || subset[i - 1][j - set[i - 1]];
        }
    }
    if(subset[n][sum / 2])
        yesno(1);
    else
        yesno(0);


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
