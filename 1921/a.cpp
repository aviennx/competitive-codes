#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

void solve(){
    vector<pair<int,int>> v;
    for(int i=0;i<4;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});

    }
    sort(v.begin(),v.end());

    int ans=v[1].second-v[0].second;

    cout<<ans*ans<<endl;
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
