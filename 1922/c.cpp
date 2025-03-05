#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x 
using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second


void solve(){
    int n;
    cin >> n;
    vl v(n);
    inp(v);
    vector<int> left(n,0),right(n,0);
    for(int i=1;i<n;i++){
            if(v[i]-v[i-1]<v[i+1]-v[i])
                left[i] = left[i-1] + 1;
            else
                left[i] = left[i-1] + v[i] - v[i-1];

    }
    left[n-1]=left[n-2]+1;
    for(int i = n-2 ; i >=1 ;i--){
        if(v[i]-v[i-1]>v[i+1]-v[i])
                right[i] = right[i+1] + 1;
            else
                right[i] = right[i+1] - v[i] + v[i+1];
    }
    right[0] = right[1] + 1;
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        if(x > y){
            cout<<left[x]-left[y]<<endl;
        }else{
            cout<<right[x]-right[y]<<endl;
        }

    }

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
