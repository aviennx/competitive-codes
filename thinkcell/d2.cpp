#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define inp(v)     for(auto &x: v) cin>>x;


void solve(){
    int n;
 	cin >> n;
 	string s;
 	cin >> s;

 	vector<long long> dp( n + 1, 0);
 	long long ans=0;

 	for(int i = n ; i > 0; i--){
 		if(s[i - 1] == '1'){
 			dp[i]= n - i + 1;
 			if(i + 3 <= n)
 				dp[i] += dp[i + 3];
 		}
 		else if( i + 1 <= n)
 			dp[i]= dp[i+1];
 		else
 			dp[i] = 0;

 		ans += dp[i];
 	}
 	cout << ans << endl;


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