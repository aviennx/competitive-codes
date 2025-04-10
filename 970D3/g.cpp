#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

int gcd(int x, int y){
    if (x < y) swap(x, y);
    while (x > y && y != 0){
        x %= y;
        swap(x, y);
    }
    return x;
}
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    if(n == 1){
        cin >> arr[0];
        if(arr[0] < k){
            cout << k << '\n';
        }else
            cout << k - 1 << '\n';
        return;
    }
    int g = -1;
    for(int& i : arr){
        cin >> i;
        if(g == -1)
            g = i;
        else
            g = gcd(g , i);
    }
    sort(arr.rbegin(), arr.rend());
    if(arr[0] == 0){
        cout << k << '\n';
        return;
    }
    vector<int> multi(n, 0);
    for(int i = 0; i < n; i++){
        multi[i] = i * g;
    }
    int l = 0, r = n;
    while(l < r){
        int m = (r + l ) >> 1;
        if(multi[r] - m - 1 >= k)
            r = m;
        else
            l = m + 1;
    }
    int ans = multi[l - 1] + k - multi[l - 1] + l;
    cout << ans - 1 << '\n';
}


int32_t main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}

