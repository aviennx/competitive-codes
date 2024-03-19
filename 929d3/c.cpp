#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int mod = 1e9 + 7;

int power(int a,int b){
    int ans=1;
    while(b){
        
        if(b%2)
            ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;

    }
    return ans;


}
void solve(){
    int a, b , l;
    cin >> a >> b >> l;
    set<int> k;

    long long cur = 1;

    for(int i = 0 ;i < 20 && cur <= l;i++)
    {   
        long long curb = 1;
        for(int j = 0; j < 20 && (cur * curb) <=l;j++)
        {
            if(l % (cur * curb) == 0)
                k.insert(l / (cur * curb));
            curb *= b;
        }
        cur *= a;
    }
    cout<<k.size()<<"\n";


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
