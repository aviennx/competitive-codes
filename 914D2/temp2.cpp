#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long

const int N = 2e5 + 5;

int rangeXOR(int n){
    if(n <= 0)
        return 0;
    int rem = n % 4;
    if(rem == 0)
        return n;
    else if(rem == 1)
        return 1;
    else if(rem == 2)
        return n + 1;
    else
        return 0;
}

int doubrange(int n){
    if(n <= 0)
        return 0;
    int rem = n % 8;
    if(rem <= 1)
        return n;
    else if(rem <= 3)
        return 2;
    else if(rem <= 5)
       return n + 2;
   else 
        return 0;
}

void solve(){
   
   int n , m , x , y;
   cin >> n >> m >> x >> y;
   int ans = rangeXOR(m -y) ^ rangeXOR(y - 1) ^ rangeXOR (x - 1) ^ rangeXOR (n - x);
   if(x - 1 > 0 && y - 1 > 0)
    ans ^= doubrange(y - 1 + x - 1) ^ doubrange(x - 1) ^ doubrange(y - 1);
   if(x - 1 > 0 && m - y > 0)
   ans ^= doubrange(x - 1) ^ doubrange(m - y) ^ doubrange(x - 1 + m - y);
   if(n - x > 0 && y - 1 > 0)
   ans ^= doubrange(n - x) ^ doubrange(y - 1) ^ doubrange(n - x + y - 1);
    if(n -x > 0 && m - y > 0)
   ans ^= doubrange(n - x) ^ doubrange(m - y) ^ doubrange(n - x + m - y);
   cout << ans << endl;

   


}


int32_t main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
