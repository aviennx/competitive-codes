#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 3;
bitset<MAX_N> isprime;
vector<int> primes;
vector<int> eratosthenesSieve(int lim) {
    isprime.set();
    isprime[0] = isprime[1] = false;
    for (int i = 4; i < lim; i += 2) isprime[i] = false;
    for (int i = 3; i * i < lim; i += 2)
        if (isprime[i])
            for (int j = i * i; j < lim; j += i * 2) isprime[j] = false;
    vector<int> pr;
    for (int i = 2; i < lim; i++)
        if (isprime[i]) pr.push_back(i);
    return pr;
}
void solve(){
    int l, r;
    cin >> l >> r;
    vector<int> arr;
    int skip = l;
    int end = r;
    end++;
    skip--;
    if((l & 1) == 0)
        skip++;
    int rnge = end - skip;
    rnge -= rnge % 4;
    map<int,vector<int>> mp;
    int ans = 0;
    for(int i = l ; i <= r; i++){
        arr.push_back(i);
        for(int j : primes)
            if(i % j == 0)
                mp[j].push_back(i);

    }
    ans = rnge / 4;
    cout << ans << '\n';
}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    primes = eratosthenesSieve(1000);
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
