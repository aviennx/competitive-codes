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
    vc <int> arr(n) , val1(n + 1), val2(n + 1);
    
    for(int& i : arr){
        cin >> i;
        val2[i]++;
    }

    int mx1 = 0, mx2 = 0;

    while(val2[mx2])
        mx2++;

    for(int i = 0; i < n; i++){
        int x = arr[i];
        val1[x]++;
        val2[x]--;
        if(mx2 >= x && val2[x] == 0)
            mx2 = x;
        while(val1[mx1])
            mx1++;
        while( mx2 - 1 >= 0 && val2[mx2 - 1] == 0)
            mx2--;
        if(mx1 == mx2){
            cout << "2\n";
            cout << 1 << " " << i + 1<< '\n';
            cout << i + 2 << " " << n << '\n';
            return;
        }
    }

    cout << "-1\n";


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