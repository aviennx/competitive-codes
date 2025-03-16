#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

void solve(){
    int n;
    cin>>n;
    map<int,int>m;
    for(int i=0; i<n-1; ++i)
    {
        int x,y;
        cin>>x>>y;
        m[x]++;
        m[y]++;
    }
    int ct=0;
    for(auto it:m)
    {
        if(it.second==1)
            ct++;
    }
    if(ct&1)
        ct++;
    cout<<ct/2<<endl;


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
