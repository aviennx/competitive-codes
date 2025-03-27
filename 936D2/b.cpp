#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;
    int sum =0 , ans = 0;
    int main_ans = 0;
    for(auto x: arr){
        sum += x;
        ans = max(ans,sum);
        if(sum < 0)
            sum = 0;
        main_ans += x;
        main_ans = (main_ans + mod) % mod;
    }
    if(ans > 0){
        for(int i = 1; i <= k; i++){
            main_ans = main_ans + ans;
            ans *= 2;
            ans %= mod;
            main_ans %= mod;
        }
    }
    while(main_ans < 0){
        main_ans += mod;
    }
    cout << (main_ans) % mod << '\n';


}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
