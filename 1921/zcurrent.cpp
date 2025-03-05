#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> mainPref(n+1,0);
    vector<int> maxsofar(n);
    vector<int> greedySum(n+1,0);
    int maxfar=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mainPref[i+1]=mainPref[i]+a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        maxfar=max(maxfar,b[i]);
        maxsofar[i]=maxfar;
        greedySum[i+1]=greedySum[i]+maxfar;
    }
    int ans=0;
    int currsum=0;
    for(int i=0;i<n && i<k;i++){
        int rem = max(0, k-i-1);
        currsum+=a[i];
        ans=max(ans,currsum+rem*maxsofar[i]);
    }
    cout<<ans<<endl;
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