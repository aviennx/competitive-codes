#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> v1(n),v2(n),v3(n);

    for( int i = 0; i < n;i++){
        cin >> v1[i].first ;
        v1[i].second = i;
    }
    for( int i = 0; i < n;i++){
        cin >> v2[i].first ;
        v2[i].second = i;
    }
    for( int i = 0; i < n;i++){
        cin >> v3[i].first ;
        v3[i].second = i;
    }
    sort(v1.rbegin() , v1.rend());
    sort(v2.rbegin() , v2.rend());
    sort(v3.rbegin() , v3.rend());

    int ans=0; 

    for(int i = 0 ; i < 3;i++){
        for(int j = 0; j <3 ;j++){
            for(int k = 0; k < 3;k++){
                if(v1[i].second != v2[j].second && v1[i].second != v3[k].second && v2[j].second != v3[k].second)
                    ans = max(ans, v1[i].first + v2[j].first + v3[k].first); 
            }
        }
    }

    cout << ans << endl;



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
