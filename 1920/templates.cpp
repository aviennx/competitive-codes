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
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


int getSqrt(int x) {
    int lo = 0, hi = 1e9, c = 0;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if((mid * mid) <= x) {
            c = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    return c;
}


vector<int> getLps(string& pat){
    int m = pat.size();
    vector<int>lps(m);
    int prev = 0;
    int ind = 1;
    while (ind < m){
        if (pat[ind]==pat[prev]){
            prev++;
            lps[ind]=prev;
            ind++;
        }
        else if (prev==0){
            lps[ind]=0;
            ind++;
        }
        else{
            prev = lps[prev-1];
        }
    }
    return lps;
}

vector<int> solve(string& str, string& pat){
    vector<int> ans;
    vector<int> lps = getLps(pat);
    int n = str.size();
    int m = pat.size();
    int patIdx = 0;
    int strIdx = 0;
 
    while (strIdx < n){
        if (str[strIdx] == pat[patIdx]){
            patIdx++;
            strIdx++;
        }
        if (patIdx == m){

            ans.push_back(strIdx - m);

            patIdx = lps[patIdx-1];
        }
        else if (strIdx < n){
            if (str[strIdx]!=pat[patIdx]){
                if (patIdx != 0)
                    patIdx = lps[patIdx-1];
                else
                    strIdx++;
            }
        }
    }
    return ans;
}



for (int k = 0; k < n; ++k) 
            if (mask & (1 << k))
                for (int i = 0; i < n; ++i)
                    if (mask & (1 << i))
                        for (int j = 0; j < n; ++j)
                            if (mask & (1 << j))
                                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
for (int i = 0; i < n; ++i)
            if (mask & (1 << i))
                for (int j = i + 1; j < n; ++j)
                    if (mask & (1 << j))
                        res = max(res, d[i][j]);


long long factorial[100001] = {}, inv_factorial[100001] = {}, mod = 1000000007;
int modPow(long long x, int y, int m)
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
long long binomial_coefficient(int n, int k) {
    return max(1LL, factorial[n] * inv_factorial[k] % mod * inv_factorial[n - k] % mod);
}
    if (!factorial[1]) {
        long long inv[100001] = {};
        factorial[1] = inv[1] = inv_factorial[1] = 1;
        for (int i = 2; i <= 100000; ++i) {
            factorial[i] = factorial[i - 1] * i % mod;
            inv_factorial[i] = modPow( factorial[i], mod - 2, mod) % mod;    
        }
    }



vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    
    sort(ids.begin(), ids.end(), [&](int i, int j) {
        return a[i] + b[i] > a[j] + b[j];
    });

