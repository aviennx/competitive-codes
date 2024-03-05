#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

void solve(){
    long long n,f,a,b;
    cin>>n>>f>>a>>b;
    vector<long long> arr(n+1,0);

    for(int i=1;i<=n;i++)
        cin>>arr[i];
    bool ans=true;
    for(long long  i=1;i<=n;i++){
        int disc=min((arr[i]-arr[i-1])*a, b);
        f-=disc;
        if(f<=0){
            ans=false;
            break;
        }
    }
    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
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

