#include<bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long 

const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int arr[MAX_N];

bool valid(ll m, int n){ 
            set<pair<int64_t,int>> pos;
            int64_t dp[n+2];
            int p2 = 1;
            dp[0] = 0;
            pos.insert({dp[0],0});
            int64_t sum = 0;
            //cout <<" l 1 " <<endl;
            for(int j = 1;j <=n; j++)
            {
                while(sum > m && p2 <= n)
                {
                    sum -= arr[p2];
                    pos.erase({dp[p2-1],p2-1});
                    p2++;
                }
                dp[j] = pos.begin()->first + arr[j];
                pos.insert({dp[j],j});
                sum += arr[j];
                //cout << j << "-";
            }
            sum = 0;
            bool yes = 0;
            //cout <<" l 2 " <<endl;

            for(int j = n ;j >= 1 ; --j)
            {
                if(sum <= m && dp[j] <= m)
                    yes = 1;
                sum += arr[j];
                //cout << j << "-";
            }

            return yes;
}




void solve(){
    int n;
    cin >> n;

    ll high = 1e15 + 5 , low  = 0;
    ll ans = high;

    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    while(low < high){
        ll mid = (low + high) / 2;
        if(valid(mid, n)){
            ans = min(ans , mid);
            high = mid ;
        }else{
            low = mid + 1;
        }
        //cout << mid <<"-" ;
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
