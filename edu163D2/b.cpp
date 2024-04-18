#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;


pair<int,int> valid(int n){
    if(n == 0)
        return {0,0};
    int last = n % 10;
    int next = INT_MAX;
    while(n != 0){
        int curr = n % 10;
        if(curr > next)
            return {-1,-1};
        next = curr;
        n /= 10;
    }
    return {next, last};
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int next = arr.back();
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] <= next){
            next = arr[i];
            continue;
        }
        if(valid(arr[i]).first == -1){
            cout << "No\n";
            return;
        }

        auto [start, end] = valid(arr[i]);
        if(end > next){
            cout << "No\n";
            return;
        }
        next = start;

    }
    cout << "YES\n";
   


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
