#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

void solve(){
    int n;
    cin>>n;
    string x,y;

    int a=0,b=0;

    cin>>x>>y;

    for(int i =0;i<n;i++){
        if(x[i]!=y[i]){
            if(y[i]=='0')
                b++;
            else
                a++;
        }
    }
    cout<<max(a,b)<<endl;
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
