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
    vector<int> a(n), b(n);
    for(int& i : a)
        cin >> i;
    for(int& i : b)
        cin >> i;
    for(int i = 0; i < n; i++){
        bool valid = false;
        if(a[i] == b[i])
            continue;
        if(a[i] > b[i]){
            cout << "No\n";
            return;
        }
        int target = b[i];
        for(int j = i - 1; j >= 0; j--){
            if(a[j] > target || b[j] < target)
                break;
            if(a[j] == target)
                valid = true;
        }
        for(int j = i + 1; j < n; j++){
            if(a[j] > target || b[j] < target)
                break;
            if(a[j] == target)
                valid = true;
        }
        if(!valid){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
   


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
