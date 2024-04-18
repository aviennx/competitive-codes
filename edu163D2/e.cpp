#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), click(n);
    int valid = min(n, k);
    int curr_click = 1;
    int index = 1;
    for(int i = 0; i < n; i += valid){
        int mid = ( valid )/ 2;
        for(int j = min(n-1, i + mid - 1); j >= i; j--)
            arr[j] = index++;       
        for(int j = min(n-1,i + valid - 1);  j >= (i + mid); j--)
            arr[j] = index++;
        for(int j = i; j < min(n, i + valid); j++)
            click[j] = curr_click;
        curr_click++;
    }
    for(int i : arr)
        cout << i << " ";
    cout << '\n';
    cout << curr_click - 1 << '\n';
    for(int i : click)
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
