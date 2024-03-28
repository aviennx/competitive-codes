#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> freq(n, 0);
    int index = 0;
    for(int& i : arr){
        cin >> i;
        freq[index++] = i;
    }
    sort(freq.begin(), freq.end());
    vector<int> pref(n);
    for(int i = 0; i < n; i++){
        pref[i] = arr[i];
        if(i)
            pref[i] += pref[i - 1];
    }
    auto calc = [&](int m){
        int sum = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] < m)
                sum += (m - arr[i]);
        return sum <= k;
    };

    int l = 1 , r = 2e12 , ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(calc(mid)){
            l = mid + 1;
            ans = mid;
        }
        else
               r = mid - 1;
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > ans)
            count++;
        else
            k -= (ans - arr[i]);
    }
    int fin = ans * n + count + k;
    fin -= (n - 1);
    cout << fin << "\n";

   


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
