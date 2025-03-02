#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for(int& i : a)
        cin >> i;
    for(int& i : b)
        cin >> i;

    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    
    sort(ids.begin(), ids.end(), [&](int i, int j) {
        return a[i] + b[i] > a[j] + b[j];
    });


    long long sum = 0;

    for( int i = 0; i < n;i++){
        if(i & 1)
            sum -= b[ids[i]] - 1;
        else
            sum += a[ids[i]] - 1;
    }

    cout << sum << endl;
}


int main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
