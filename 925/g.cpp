#include<bits/stdc++.h>
using namespace std;

long long factorial[2000001] = {}, inv_factorial[2000001] = {}, mod = 998244353;

long long modPow(long long x, int y, int m)
{
    long long ans=1;
    if (y == 0)
        return 1;
    while(y>0){
        if(y % 2 == 1)
            ans = ans * x % m;
        y >>= 1;
        x = x * x % m;
    }
    return ans % m;
}
long long binomial_coefficient(long long n, long long k) {
    return max(1LL, factorial[n] * inv_factorial[k] % mod * inv_factorial[n - k] % mod);
}
void solve(){
    long long arr[4] = {};
    for(int i = 0; i < 4; i++)
        cin >> arr[i];
    long long p = arr[0], iv = arr[1], l1 = arr[3], r1 = arr[2];

    if (!factorial[1]) {
        long long inv[1000005] = {};
        factorial[1] = inv[1] = inv_factorial[1] = 1;
        for (int i = 2; i <= 2000000; ++i) {
            factorial[i] = factorial[i - 1] * i % mod;
            inv_factorial[i] = modPow( factorial[i], mod - 2, mod) % mod;    
        }
    }


    if(abs(p - iv) > 1){
        cout << 0 << '\n';
        return;
    }
    if (p == 0 && iv == 0) {
        cout << (min(r1, l1) ? 0 : 1) << '\n';
        return;
    }
    long long ans = 0;
    if(p > iv){
        ans = binomial_coefficient(r1 + p - 1, p - 1);
        ans = ans * binomial_coefficient(l1+ p - 1, p - 1) % mod;

    }else if(iv > p){
        ans = binomial_coefficient(r1 + iv - 1, iv - 1);
        ans = ans * binomial_coefficient(l1 + iv - 1, iv - 1) % mod;
    }else{
        long long ans1 = binomial_coefficient(r1 + p - 1, p - 1);
        ans1 = ans1 * binomial_coefficient(l1 + p , p ) % mod;

        long long ans2 = binomial_coefficient(r1 + p , p );
        ans2 = ans2 * binomial_coefficient(l1 + p - 1, p - 1) % mod;

        ans = ans1 + ans2 % mod;
    }

    cout << ans % mod << '\n';

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
