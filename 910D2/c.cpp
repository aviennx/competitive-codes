#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    if(k<n+m-2||k%2!=(n+m)%2){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++)cout<<(j%2?"B ":"R ");
            cout<<"\n";
        }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0)
                cout<<"B ";
            else
                cout<<((i+j)%2?"B ":"R ");
        }
        cout<<"\n";
    }


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
