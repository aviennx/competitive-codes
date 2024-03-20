#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    int l = arr[0], r = arr[n - 1];
    int sum = r - l;
    int best = sum + abs(arr[0] - arr[1]) + abs(arr[1] - arr[2]) + abs(arr[2] - arr[3 ]);
    for(int i = 1; i < n - 1; i++){
        for(int j = 1 ; j < n - 1; j++){
            if(i == j)
                continue;
            int curr = sum + abs(arr[0] - arr[i]) + abs(arr[i] - arr[j]) + abs(arr[j] - arr[n -1 ]);
            if(curr > best )
                best = curr;
        } 
    }
    cout << best << endl;

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
