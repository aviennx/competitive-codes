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
constexpr int B = 200;

void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    inp(a);
    vector<long long> answer(q);
    vector<vector<array<int,3>>> queries(n+1);

    for(int i=0;i<q;i++){
        int s,d,k;
        cin >> s >> d >> k;
        s--;
        if(d>B){
            long long ans=0;
            for(int j=1;j<=k;j++){
                ans += 1LL * a[s+(j-1)*d]*j;
            }
            answer[i]=ans;
        }else{
            queries[d].push_back({s,k,i});
        }
    }


    for(int d = 1 ; d < n+1 ; d++){
        if(queries[d].empty())
            continue;

        vector<long long> arr1(n),arr2(n);
        for(int i=0;i<n;i++){
            arr1[i] = 1LL * (i/d + 1) * (a[i]);
            arr2[i] = a[i];
            if(i>=d){
                arr1[i] += arr1[i-d];
                arr2[i] += arr2[i-d];
            }
        }

        for(auto [s,k,index] : queries[d]){
            long long sum = arr1[ s + (k - 1) * d] - 
            ( s >= d ? arr1[ s - d] : 0 )
            - 1LL * ( s/d  ) * (arr2[ s + (k - 1) * d] -
            ( s>=d ? arr2[ s - d] : 0));
            answer[index] = sum;
        }

    }
    for(auto i:answer)
        cout << i << " ";
    cout << endl;



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
