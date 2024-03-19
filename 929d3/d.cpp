#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 
#define ll long long

void solve(){
    int n;
      cin>>n;
      vector<ll> v(n);
      int cnt=0;
      for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]==1){
                  cnt++;
            }
      }

      if(cnt==1){
            cout<<"YES\n";
            return;
      }

      if(cnt>1){
            cout<<"NO\n";
            return;
      }

      sort(v.begin(),v.end());
      bool flag=true;

      for(int i=1;i<n;i++){
            if(v[i]%v[0]!=0){
                  flag=false;
            }
      }

      if(flag && v[0]==v[1]){
            cout<<"NO\n";
            return;
      }
      
      cout<<"YES\n";
      return;

}


int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
