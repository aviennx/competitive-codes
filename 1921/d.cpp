#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int l2=0,r2=m-1;
    int l1=0,r1=n-1;
    long long d=0;
    while(l1<=r1){
        long long l1_l=abs(a[l1]- b[l2]);
        long long l1_r=abs(a[l1]-b[r2]);
        long long lbest=max(l1_l,l1_r);
        long long r1_l=abs(a[r1]-b[l2]);
        long long r1_r=abs(a[r1]-b[r2]);
        long long rbest=max(r1_l,r1_r);

        if(lbest>=rbest){
            d+=lbest;
            l1++;
            if(l1_l>=l1_r)
                l2++;
            else
                r2--;
        }else{
            d+=rbest;
            r1--;
            if(r1_l>=r1_r)
                l2++;
            else
                r2--;
        }
    }
    cout<<d<<endl;
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
