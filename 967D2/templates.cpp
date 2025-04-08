template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


auto dfs = y_combinator([&](const auto &self,int u,int par)->void{
            for(auto &x:adj[u]){
                if(x==par)
                    continue;
                self(x,u);
            }
        });
        dfs(0,-1);

        
//median check 

auto chk = [&](int med){
        int less = 0;
        ll cst = 0;

        for (auto [a, b] : A)
            if (a < med)
                less++;
        
        for (int i = A.size() - 1; i >= 0 ; i--){
            if (A[i].first < med and A[i].second and less > n / 2 - 1){
                cst += med - A[i].first;
                less--;
            }
        }
        return less <= n / 2 - 1 and cst <= k;
    };



//mod add sub
const int M = 1000000007;
    
    void add(int &x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
    }
    
    void dec(int &x, int y) {
        if ((x -= y) < 0) {
             x += M;
        }
    }
//flush
fflush(stdout);
//Tree Dp example


class Solution {
public:
    int n;
    std::vector<std::vector<int>> adj;   
    vector<pair<int,int>> dp;
    vector<int> times;
    void dfs(int curr, int p){
        for(int next : adj[curr]){
            if(next == p)
                continue;
            dfs(next, curr);
            int w = 1 + (1 - next % 2);
            if((w + dp[next].first )> dp[curr].first){
                dp[curr].second = dp[curr].first;
                dp[curr].first = w + dp[next].first;
                
            }else if(w + dp[next].first > dp[curr].second)
                dp[curr].second= w + dp[next].first ;
        }
    }
    void dfs2(int curr, int p, int up = 0){
        if(curr != 0)
            times[curr] = max(up, dp[curr].first);
        else
            times[curr] = dp[curr].first;
        for(int next : adj[curr]){
            if(next == p)
                continue;
            int w = 1 + (1 - curr % 2);
            int w_D = 1 + (1 - next % 2);
            if((w_D + dp[next].first ) == dp[curr].first)
                dfs2(next, curr, max(up, dp[curr].second) + w);
            else
                dfs2(next, curr, times[curr] + w);
        }
    }
    vector<int> timeTaken(vector<vector<int>>& edges) {
        n = edges.size() + 1;
        adj.resize(n);
        dp.resize(n, {0, 0});
        times.resize(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        //for(auto [x, y]: dp)
         //   cout << x << " "<< y <<endl;
        dfs2(0, -1);
        return times;
    }
};

//string hash and trie


#define ll long long
//rolling hash prefix 
const int MOD = 1e9 + 7;
const int p = 373;
ll fpow(ll b, ll p){
    ll r = 1;
    for(; p; p>>=1, b=b*b%MOD) if(p&1) r=r*b%MOD;
    return r;
}
ll minv(ll a) { return fpow(a, MOD-2); }
class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        vector<int> sz;
        int n = target.size();
        vector<ll> pw(n,1);
        vector<ll> rev(n,1);
        //unordered_map<ll, int> best;
        for(int i=1; i<n; i++)
            pw[i] = pw[i-1] * p % MOD;
        for(int i=0; i<n; i++)
            rev[i] = minv(pw[i]);
        
        ll hsh[n];
        for(int i=0; i<n; i++) {
            hsh[i] = (i ? hsh[i-1] : 0) + pw[i] * (target[i] - 'a' + 1) % MOD;
            hsh[i] %= MOD;
        }
        vector<ll> dp(n + 1, INT_MAX);
        unordered_map<long long,int> mp;
        for(int i = 0; i < words.size(); i++){
            if(words[i].size() > n) {
                continue;
            }
            long long hash = 0;
            for(int j=0; j<words[i].size(); j++) {
                hash += pw[j] * (words[i][j] - 'a' + 1) % MOD;
                hash %= MOD;
            }
            if(mp.count(hash))
                mp[hash] = min(mp[hash], costs[i]);
            else
                mp[hash] = costs[i];
            sz.push_back(words[i].size());
        }
        sort(sz.begin(), sz.end());
        sz.resize(unique(sz.begin(), sz.end()) - sz.begin());
        for(int i = 0; i < n; i++){
            ll pv = (i ? dp[i - 1] : 0);
            if(pv >= INT_MAX) continue;
            for(int s : sz){
                if(i + s - 1 >= n)
                    break;
                int r = i + s - 1;
                int l = i;
                ll goal = (hsh[l + s - 1] - (l?hsh[l-1]:0) + MOD) % MOD;
                goal = goal * rev[i] % MOD;
                if(!mp.count(goal))
                    continue;
                dp[l + s - 1] = min(dp[l + s - 1], pv + mp[goal]);
            }
        }
        return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
    }
};


const int N = 5e4+10;
int t[N][26]; 
long c[N+100], MX = 1e9;
int sz = 0;

int get_node(){
    fill(t[sz],t[sz]+26,-1);
    c[sz]=MX;
    sz++;
    return sz-1;
}

void insert(string &w, long p){
    int cur=0;
    for(auto ch: w){
        if(t[cur][ch-'a']==-1)t[cur][ch-'a']=get_node();
        cur=t[cur][ch-'a'];
    }
    c[cur]=min(c[cur], p);
}


class Solution {
public:
    
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n=target.size();
        int len=0;
        sz=0;
        for(auto &word: words){
            len+=word.size();
        }
        // for(int i = 0; i < len+10; i++){
        //     fill(t[i],t[i]+26,-1);
        // }
        // fill(c,c+len*26,MX);
        auto _ = get_node();
        for(int i=0;i<words.size();i++){
            insert(words[i], costs[i]);
        }
        vector<long> dp(n+1);
        dp[n]=0;
        
        for(int i = n-1; i >= 0; i--){
            dp[i]=MX;
            char ch;
            for(int j = i, cur=0; j < n; j++){
                ch=target[j];
                if(t[cur][ch-'a'] == -1)break;
                else {
                    cur=t[cur][ch-'a'];
                    if(dp[j+1]<MX){
                        dp[i]=min(dp[i], c[cur]+dp[j+1]);
                    }
                }
                // cout<<ch<<"";
            }
            // cout<<"\n";
        }
        // for(int i=0;i<n;i++)cout<<dp[i]<<" ";cout<<"\n";
        if(dp[0]>=MX)dp[0]=-1;
        return dp[0];
    }
};



auto dfs = [&] (const auto &self, int u, int p) -> void {
            in[u] = timer++;
            for (int v : adj[u]) {
                if (v == p) continue;
                self(self, v, u);
            }
            out[u] = timer;
        };
     
a.resize(unique(a.begin(), a.end()) - a.begin());

//rolling hash
int longestCommonSubpath(int n, vector<vector<int>>& ps) {
    int l = 0, r = min_element(begin(ps), end(ps), [](const auto& a, const auto &b){ return a.size() < b.size(); })->size();
    long long base = 100001, mod = 100000000019;
    while (l < r) {
        int m = (l + r + 1) / 2;
        unordered_set<long long> hs;
        for (int i = 0; i < ps.size() && (i == 0 || !hs.empty()); ++i) {
            long long hash = 0, d = 1;
            unordered_set<long long> hs1;
            for (int j = 0; j < ps[i].size(); ++j) {
                hash = (hash * base + ps[i][j]) % mod;
                if (j >= m)
                    hash = (mod + hash - d * ps[i][j - m] % mod) % mod;
                else
                    d = d * base % mod;    
                if (j >= m - 1 && (i == 0 || hs.count(hash)))
                    hs1.insert(hash);
            }
            swap(hs, hs1);
        }
        if (hs.empty())
            r = m - 1;
        else
            l = m;            
    }
    return l;
}


//rolling hash prefix 
const int MOD = 1e9 + 7;
const int p = 373;
ll fpow(ll b, ll p){
    ll r = 1;
    for(; p; p>>=1, b=b*b%MOD) if(p&1) r=r*b%MOD;
    return r;
}
ll minv(ll a) { return fpow(a, MOD-2); }


        vector<ll> pw(n,1);
        vector<ll> rev(n,1);
        unordered_map<ll, int> best;
        set<int> sz;
        for(int i=0; i<words.size(); i++)
            sz.insert(words[i].size());
        
        for(int i=1; i<n; i++) pw[i] = pw[i-1] * p % MOD;
        for(int i=0; i<n; i++) rev[i] = minv(pw[i]);
        
        ll hsh[n];
        for(int i=0; i<n; i++) {
            hsh[i] = (i ? hsh[i-1] : 0) + pw[i] * (target[i] - 'a' + 1) % MOD;
            hsh[i] %= MOD;
        }

        ll h = 0;
            for(int j=0; j<words[i].size(); j++) {
                h += pw[j] * (words[i][j] - 'a' + 1) % MOD;
                h %= MOD;
            }
    x = lenghthhh
    if(i+x-1 >= n) break;
    ll goal = (hsh[i + x - 1] - (i?hsh[i-1]:0) + MOD) % MOD;
    goal = goal * rev[i] % MOD;


const int MOD = 1e9 + 7;
template <int MOD = 1000000007>
struct Mint {
private:
  unsigned int val;

public:
  template <typename T>
  constexpr Mint(T x) noexcept : val(x < 0      ? x % MOD + MOD
                                     : x >= MOD ? x % MOD
                                                : x) {}

  constexpr Mint &operator+() noexcept { return *this; }
  constexpr Mint &operator-() noexcept { return Mint(0) - *this; }

  constexpr Mint &operator+=(const Mint &rhs) noexcept {
    if ((val += rhs.val) >= MOD) val -= MOD;
    return *this;
  }
  constexpr Mint &operator-=(const Mint &rhs) noexcept {
    if ((val -= rhs.val) >= MOD) val += MOD;
    return *this;
  }
  constexpr Mint &operator*=(const Mint &rhs) noexcept {
    val = static_cast<unsigned long long>(val) * rhs.val % MOD;
    return *this;
  }

  constexpr Mint operator+(const Mint &rhs) const noexcept { return Mint(*this) += rhs; }
  constexpr Mint operator-(const Mint &rhs) const noexcept { return Mint(*this) -= rhs; }
  constexpr Mint operator*(const Mint &rhs) const noexcept { return Mint(*this) *= rhs; }

  // log(MOD)
  constexpr Mint &operator/=(const Mint &rhs) noexcept { return *this *= rhs.inv(); }
  // log(MOD)
  constexpr Mint operator/(const Mint &rhs) const noexcept { return Mint(*this) /= rhs; }

  // log(n)
  constexpr Mint pow(long long n) const noexcept {
    Mint ret(1), mul(val);
    while (n) {
      if (n % 2) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  // log(MOD). MOD must be prime.
  constexpr Mint inv() const noexcept { return pow(MOD - 2); }

  constexpr bool operator==(const Mint &rhs) const noexcept { return val == rhs.val; }
  constexpr bool operator!=(const Mint &rhs) const noexcept { return val != rhs.val; }

  friend constexpr Mint operator+(long long lhs, const Mint &rhs) { return Mint(lhs) += rhs; }
  friend constexpr Mint operator-(long long lhs, const Mint &rhs) { return Mint(lhs) -= rhs; }
  friend constexpr Mint operator*(long long lhs, const Mint &rhs) { return Mint(lhs) *= rhs; }
  // log(MOD)
  friend constexpr Mint operator/(long long lhs, const Mint &rhs) { return Mint(lhs) /= rhs; }

  friend constexpr bool operator==(long long lhs, const Mint &rhs) { return lhs == rhs.val; }
  friend constexpr bool operator!=(long long lhs, const Mint &rhs) { return lhs != rhs.val; }

  friend std::ostream &operator<<(std::ostream &os, const Mint<MOD> &x) { return os << x.val; }
  friend std::istream &operator>>(std::istream &is, Mint<MOD> &x) {
    long long val_;
    is >> val_;
    x = val_;
    return is;
  }
};

array<vector<int>, 2> manacher(vector<int>& s)
{
    int n = s.size();
    array<vector<int>,2> p = {vector<int>(n+1), vector<int>(n)};
    for (int z = 0; z < 2; ++z) {
        for (int i = 0, l = 0, r = 0; i < n; ++i) {
            int t = r - i + !z;
            if (i < r) p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
                p[z][i]++, L--, R++;
            if (R > r) l = L, r = R;
        }
    }
    return p;
}

//
//hi-low set

void insert(int val, multiset<int>& low, multiset<int>& high, int& sum_high, int& sum_low) {
    // Initial configuration
    if (high.empty() || val >= *high.begin()) {
        high.insert(val);
        sum_high += val;
    } else {
        low.insert(val);
        sum_low += val;
    }
    
    // Rebalancing heaps
    if (high.size() > low.size() + 1) {
        low.insert(*high.begin());
        sum_low += *high.begin();
        sum_high -= *high.begin();
        high.erase(high.find(*high.begin()));
    } else if (low.size() >= high.size()) {
        high.insert(*low.rbegin());
        sum_high += *low.rbegin();
        sum_low -= *low.rbegin();
        low.erase(low.find(*low.rbegin()));
    }
}



//bfs
        vector<vector<int>> d( n , vector<int> (m, INT_MAX));
        deque<pair<int, int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    d[i][j]=a[i][j]-'0';
                    if(a[i][j]=='0')
                        q.push_front({i,j});
                    else
                        q.push_back({i,j});
                }
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!q.empty()) {
            pair<int,int> cur = q.front();
            int x = cur.first;
            int y = cur.second;
            q.pop_front();
            for(int i=0;i<4;i++)
            {
                int adj_x = x+dx[i];
                int adj_y = y+dy[i];
                if(adj_x<0 || adj_x>=n || adj_y<0 || adj_y>=m)
                    continue;
                int weight = a[adj_x][adj_y]-'0';
                if (d[x][y] + weight < d[adj_x][adj_y]) {
                    d[adj_x][adj_y] = d[x][y] + weight;
                    if (weight == 1)
                        q.push_back({adj_x,adj_y});
                    else
                        q.push_front({adj_x,adj_y});
                }
            }
        }
void merge(vector<int> &arr, int l, int mid, int r, int &ic){
    vector<int> left, right;
    for(int i=l;i<=mid;i++) left.pb(arr[i]);
    for(int i=mid+1;i<=r;i++) right.pb(arr[i]);
 
    int i=0; int j=0;
    int n1 = left.size(); int n2 = right.size();
 
    int k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k++] = (left[i++]);
        }
        else{
            arr[k++] = (right[j++]);
            ic+=(n1-i);
        }
    }
    while(i<n1){
        arr[k++] = (left[i++]);
    }
    while(j<n2){
        arr[k++] = (right[j++]);
    }
}
 
void mergesort(vector<int> &arr, int l, int r, int &ic){
    if(l>=r) return;
    int mid = (l+r)/2;
    mergesort(arr, l, mid, ic);
    mergesort(arr, mid+1, r, ic);
 
    merge(arr, l, mid, r, ic);
}
 
int find_inversion_count(vector<int> &arr){
    int n = arr.size();
    int ic=0;
    mergesort(arr, 0, n-1, ic);
    return ic;
}
 
 

All permutations // 

    sort(str.begin(), str.end());
 
    // Keep printing next permutation while there
    // is next permutation
    do {
       cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));


int gcd(int x, int y){
    if (x < y) swap(x, y);
    while (x > y && y != 0){
        x %= y;
        swap(x, y);
    }
    return x;
}


frequency compression //

    vector<pair<ll, ll>> a_comp;
    for(int i = 0; i < 2 * n; i++){
        if(a_comp.size() == 0u || a_comp.back().first != a[i]){
            a_comp.push_back({a[i], 1});
        }else{
            a_comp.back().second++;
        }
    }

is prime //

bool is_prime(ll n){
    if(n == 1){
        return false;
    }
    for(ll i = 2; i * i <= n; i++){
        if(n %i == 0){
            return false;
        }
    }
    return true;
}




Bitset prime //

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
primes = eratosthenesSieve(MAX_N);

Prime counter // 

    vector<ll> isprime(N, 1), lp(N);
    for(ll i=2;i<N;i++) {
        if(isprime[i]==0 || lp[i])   
            continue;
        lp[i] = i;
        for(ll j=2*i;j<N;j+=i) {
            isprime[j] = 0;
            if(lp[j]==0)
                lp[j] = i;
        }
    }

    vector<ll> sums(N);
    for(ll i = 1; i < N; i++) {
        ll sum = 0, curr = i;
        while(curr != 1) {
            ll t = lp[curr];
            while(curr % t == 0) {
                curr /= t;
                sum += 1;
            }
        }
        sums[i] = sum;
    }



#define ll long long

const int MAX = 2e6 + 5, MOD = 998244353;

ll fact[MAX], ifact[MAX];

ll bpow(ll a, int p){
    ll ans = 1;

    for (;p; p /= 2, a = (a * a) % MOD) 
        if (p & 1) 
            ans = (ans * a) % MOD;

    return ans;
}
ll ncr(int n, int r){
    if (n < 0)
        return 0;
    if (r > n)
        return 0;

    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

for (int i = 0; i < MAX; i++)
        fact[i] = !i ? 1 : fact[i - 1] * i % MOD;
    
for (int i = MAX - 1; i >= 0; i--)
    ifact[i] = (i == MAX - 1) ? bpow(fact[MAX - 1], MOD - 2) : ifact[i + 1] * (i + 1) % MOD;




int x = find_if(a.begin(), a.end(), [&](int v) { return v > a[k]; }) - a.begin();

vector<int> parents;
    vector<int> setw;
    vector<int> sz;
    int _find(int u){
        while(u != parents[u]){
            u = parents[u];
        }
        return parents[u];
    }
    void _join(int u, int v,int w){
        int a = parents[u], b = parents[v];
        if(a == b){
            setw[a] &= w;
            setw[b] &= w;
            return;
        }
        
        if(sz[a] > sz[b]){
            sz[a] += sz[b];
            setw[a] &= w;
            setw[a] &= setw[b];
            setw[b] &= setw[a];
            parents[b] = a;
        }else{
            sz[b] += sz[a];
            setw[b] &= w;
            setw[b] &= setw[a];
            setw[a] &= setw[b];
            parents[a] = b;
        }
    }
    parents.resize(n);
        setw.resize(n);
        sz.resize(n);
        for(int i = 0 ; i < n; i++){
            parents[i] = i;
            sz[i] = 1;
            setw[i] = (1 << 20) - 1;
        }

int sqrt(int a)
{
  int l = 0;
  int r = 1e9;
  int ans = 0;
  while (l <= r)
  {
    int mid = l + ((r - l) / 2);
    if (mid * mid <= a)
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  return ans;
}


void printarray(vector<int> &a){
    for(int i=0 ; i<(int)a.size() ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int acc(vi &a){
    int sum=0;for(auto e : a){sum+=e;}
    return sum;
}



const int MOD = 998244353;

int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int mul(int x, int y) {
  return x * 1LL * y % MOD;
}

int binpow(int x, int y) {
  int z = 1;
  while (y) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}

int inv[2000000] = {};
    factorial[1] = inv[1] = inv_factorial[1] = 1;
    for (int i = 2; i <= scount + 1; ++i) {
            factorial[i] = mul(factorial[i - 1] , i )% mod;  
    }

    inv_factorial[scount] = binpow(factorial[scount], MOD - 2);
    for (int i = scount; i > 0; --i)
        inv_factorial[i - 1] = mul(inv_factorial[i], i);
 
/**
 * Manacher's Algorithm
 * Source: kactl
 * Description: p[0][i] is the half-length of the longest even palindrome centered about (i-1, i)
 *              p[1][i] is the half-length (rounded down) of the longest odd palindrome about i
 * Time: O(N)
 */vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}



array<vector<int>, 2> manacher(const string& s)
{
    int n = s.size();
    array<vector<int>,2> p = {vector<int>(n+1), vector<int>(n)};
    for (int z = 0; z < 2; ++z) {
        for (int i = 0, l = 0, r = 0; i < n; ++i) {
            int t = r - i + !z;
            if (i < r) p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
                p[z][i]++, L--, R++;
            if (R > r) l = L, r = R;
        }
    }
    return p;
}
 

 
vector<int> manacher(string s) {
    string t = "#";
    for(auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> r(n);
    for(int i = 0,j = 0;i < n;i ++) {
        if(2 * j - i >= 0 && j + r[j] > i) {
            r[i] = min(r[2 * j - i],j + r[j] - i);
        }
        while(i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]){
            r[i] += 1;
        }
        if(i + r[i] > j + r[j]) j = i;
    }
    return r;
}



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


vector<long long> sieve(int n){
    int*arr = new int[n + 1]();
    vector<long long> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0){
                vect.push_back(i);
                for (int j = 2 * i; j <= n; j += i)
                    arr[j] = 1;
            }
            return vect;
        }

vector<long long> prime=sieve(1e5);


for(auto x:prime){
          if(x*x>temp) break;
          while(temp%x==0){
               temp/=x;
               div[x]++;
          }
      }

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


vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        for (int &j = z[i]; i + j < n && s[j] == s[i + j]; j++);
        if (z[i] > r - i + 1)
            l = i, r = i + z[i] - 1;
    }
    return z;
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


//index sort
vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    
    sort(ids.begin(), ids.end(), [&](int i, int j) {
        return a[i] + b[i] > a[j] + b[j];
    });

// bfs

    vector<vector<int>> grid, visit, dist;
int n, m;
bool valid(int x,int y){
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 1;
}
vector<pair<int,int>> dirs = {{1 , 0} , {-1 , 0} , {0 , 1} , {0, -1}};
vector<pair<int,int>> Alldirs = {{1 , 0} , {-1 , 0} , {1 , 1} , {-1, -1}, {0 , 1}, {0, -1} , {-1, 1}, {1 , -1}};

void build_dist(vector<pair<int,int>>& q){
    int n = grid.size(), m = grid[0].size();

    vector<pair<int,int>> curr = q;

    while(!curr.empty()){
        vector<int> next;
        int sz = curr.size();

        for(int i = 0; i < sz; i++){
            auto [x, y] = q[i];
            for( auto [nx, ny] : dirs){
                int X = x + nx;
                int Y = y + ny;
                if(valid( X, Y) && dist[X][Y] > dist[x][y] + 1){
                    next.push_back({X , Y});
                    dist[X][Y] = dist[x][y] + 1;
                }
            }

        }
        
        swap(curr , next)
    }
}

//bfs end




void debug2D(vector<vector<int>>& arr){
    int N = arr.size(), M = arr[0].size();
    cout << "------------------------" << endl;
    cout << "debugging array of size N = " << N << " and M = " << M << endl;

    for(int i = 0; i < M ;i++){
        for(int j : arr[i])
            cout << j << " ";
        cout << endl;
    } 

    cout << "------------------------" << endl;
}

void debug1D(auto& arr){
    int N = arr.size();
    cout << "------------------------" << endl;
    cout << "debugging array of size N = " << N << endl;

    for(int j : arr)
            cout << j << " ";
    cout << endl;

    cout << "------------------------" << endl;
}


vector<int> getPrimes(int x){
        vector<int> ans;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                ans.push_back(i);
                while(x%i==0)
                    x/=i;
            }
        }
        if(x>1)
            ans.push_back(x);
        return ans;
    }




class graph{
  public:
    int n;
    vector<vector<int>> edges;
    vector<bool> visited;
    int counter;
    graph(int x){
        n=x;
        edges.resize(n);
    }
    void add_edge(int a,int b){
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    void dfs(int curr,int prev){
        visited[curr]=true;
        counter++;
        for(auto next:edges[curr]){
            if(!visited[next]&&next!=prev)
                dfs(next,curr);
        }
    }
    bool checkCon(){
        visited.resize(n,false);
        counter=0;
        dfs(0,-1);
        return counter==n;
    }
};



#define pii pair<int,int>
class Graph {
public:
    vector<vector<pii>> al;
    Graph(int n, vector<vector<int>>& edges) {
        al.resize(n);
        for (const auto &e : edges)
            al[e[0]].push_back({e[1], e[2]});
    }
    void addEdge(const vector<int> &e) {
        al[e[0]].push_back({e[1], e[2]});
    }
    int shortestPath(int node1, int node2) {
        priority_queue<pii, vector<pii>, greater<>> pq;
        int cost[101]={};
        for(int i=0;i<101;i++)
            cost[i]=INT_MAX;
        cost[node1] = 0;
        pq.push({0, node1});
        while (!pq.empty() && pq.top().second != node2) {
            auto [cost_i, i] = pq.top();
            pq.pop();
            if (cost_i != cost[i])
                continue;
            for(auto [j, cost_j] : al[i])
                if (cost_i + cost_j < cost[j]) {
                    cost[j] = cost_i + cost_j;
                    pq.push({cost[j], j});
                }
        }
        return cost[node2] == INT_MAX ? -1 : cost[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */



class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int ans=-1;
        vector<vector<int>> adj(n);
        for(auto& x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(auto& x:edges)
            search(x,adj,ans);
        return ans==-1?-1:ans+1;
    }
private:
    void search(vector<int>& skip,vector<vector<int>>& adj,int& ans){
        queue<int> q;
        q.push(skip[0]);
        vector<int> dist(adj.size(),-1);
        dist[skip[0]]=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            int d=dist[curr]+1;
            if(ans>=0 && d>=ans)
                return;
            for(int next:adj[curr]){
                if((next==skip[1]&&curr==skip[0])||(next==skip[0]&&curr==skip[1])||dist[next]>=0)
                    continue;
                if(next==skip[1]){
                    ans=d;
                    return;
                }
                q.push(next);
                dist[next]=d;
            }
        }
    }
};


sort(tasks.begin(),tasks.end(),[](const auto& a,const auto& b){
            return a[1]<b[1];
        });

vector<int> getPrimes(int x){
        vector<int> ans;
        for(int i=2;x>1 && i<1000;i+=1+(i%2)){
            if(x%i==0){
                ans.push_back(i);
                while(x%i==0)
                    x/=i;
            }
        }
        if(x>1)
            ans.push_back(x);;
        return ans;
    }
bool checkBip(int n){
        vector<int> visited(n+1,-1);
        for(int i=1;i<=n;i++)
            if(visited[i]==-1 && !Bip(i,visited))
                return false;
        return true;                
    }
    bool Bip(int start,vector<int>& grp){
        queue<int> q;
        q.push(start);
        grp[start]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int next:adj[curr]){
                if(grp[next]==-1){
                    grp[next]=1-grp[curr];
                    q.push(next);
                }else if(grp[next]==grp[curr])
                    return false;
            }
        }
        return true;
    }



    void dfs(int curr,int prev){
        if(prev!=-1)
            lvl[curr]=lvl[prev]+1;
        parent[0][curr]=prev==-1?0:prev;
        for(int i=1;i<=14;i++)
            parent[i][curr]=parent[i-1][parent[i-1][curr]];
        for(auto& [next,w]:adj[curr]){
            if(next==prev)
                continue;
            dp[next]=dp[curr];
            dp[next][w]++;
            dfs(next,curr);
        }
    }
    int search(int a,int b){
        if(lvl[b]>lvl[a])
            swap(a,b);
        int to_fix=lvl[a]-lvl[b];
        if(to_fix){
            for(int i=14;i>=0;i--){
                if(to_fix&(1<<i))
                    a=parent[i][a];
            }
        }
        if(a==b)
            return a;
        for(int i=14;i>=0;i--){
            if(parent[i][a]!=parent[i][b]){
                a=parent[i][a];
                b=parent[i][b];
            }
        }
        return parent[0][a];
    }



using int2=pair<int, int>;
    struct cmp{
        bool operator()(int2& x, int2& y){
            return x.second>y.second;
        }
    };
priority_queue<int2, vector<int2>, cmp> pq(freq.begin(), freq.end());



     
const int MOD = 1e9 + 7;
struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    // friend Mint operator<=(const Mint &a, const Mint &b) { return (int)a <= (int)b; }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};




vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        for (int &j = z[i]; i + j < n && s[j] == s[i + j]; j++);
        if (z[i] > r - i + 1)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
class Solution {
    long long mod = (int64_t)1e17 + 3;
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        unordered_map<int64_t, int> cnt;
        long long ans = 0;
        for (auto &w : words) {
            auto z = z_function(w);
            int64_t h = 0;
            for (int n = w.size(), i = 1; i <= n; i++) {
                h = (h * 27LL + (1LL + w[i - 1] - 'a')) % mod;
                if (z[n - i] == i) {
                    auto it = cnt.find(h);
                    if (it != cnt.end())
                        ans += it->second;
                }
            }
            cnt[h]++;
        }
        return ans;
    }
};




////DIAMETER !!!


void dfs(vector<int> adj[],int dis[],int par[],int u,int p)
{
    par[u]=p;
    for(auto v:adj[u])
    {
        if(v!=p)
        {
            dis[v]=dis[u]+1;
            dfs(adj,dis,par,v,u);
        }
    }
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> adj[n];
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dis[n],par[n];
    dis[0]=0;
    dfs(adj,dis,par,0,0);
    int r=0;
    for(int i=0;i<n;i++)
        if(dis[r]<dis[i])
            r=i;
    dis[r]=0;
    dfs(adj,dis,par,r,r);
    int l=r;
    for(int i=0;i<n;i++)
        if(dis[l]<dis[i])
            l=i;
    vector<int> diameter;
    int u=l;
    while(u!=r)
    {
        diameter.push_back(u);
        u=par[u];
    }
    diameter.push_back(r);

///// end

class UnionFind { // usual UnionFind class
    vector<int> root, rank;
public:
    UnionFind(int n) : root(n), rank(n) {
        rank.assign(n, 1);
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {
        if (x == root[x])
            return x;
        else
            return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
        int rX = Find(x), rY = Find(y);
        if (rX == rY)
            return;
        if (rank[rX] > rank[rY])
            swap(rX, rY);
        root[rX] = rY;
        if (rank[rX] == rank[rY])
            rank[rY]++;
    }
    bool connected(int x, int y) { return Find(x) == Find(y); }
};




typedef pair<int, int> pii;

    class Solution {
public:
        
    vector<int> Djikstra(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pii>> g(n + 1);
        for (const auto& t :edges) {
            g[t[0]].emplace_back(t[1], t[2]);
            g[t[1]].emplace_back(t[0], t[2]);
            
        }
        const int inf = 1e9;
        vector<int> dist(n, inf);
        vector<bool> vis(n, false);
        dist[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.emplace(0, 0);
        int u, v, w;
        while (!pq.empty()) {
            u = pq.top().second; pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (auto& to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w && disappear[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        for(int& i : dist)
            if(i > 100000000)
                i = -1;
        return dist;
    }
};



inclusion exclusion
        int m = coins.size();
        int nn = (1 << m);
        long long cnt = 0;
        for (int i = 1; i < nn; i++)
        {
            long long lcmm = 1;
            for (int j = 0; j < m; j++)
            {
                if (i & (1 << j))
                {
                    lcmm = lcm(lcmm, coins[j]);
                }
            }
            if (__builtin_popcount(i) & 1)
                cnt += x / lcmm;
            else
                cnt -= x / lcmm;
        }
        return cnt;
segtree max and range reduce 


class Solution {
public:
    int N = 50005;
    int MAX = 4 * 50005 + 5;
    int arr[50005];
    int tree[4 * 50005 + 5];
    int lazy[4 * 50005 + 5];

    void build_tree(int node, int a, int b) {
        if(a > b) return;   
        if(a == b) {
            tree[node] = arr[a];
            return;
        }
        build_tree(node*2, a, (a+b)/2);
        build_tree(node*2+1, 1+(a+b)/2, b);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    void update_tree(int node, int a, int b, int i, int j, int value) {
        if(lazy[node] != 0) { 
            tree[node] += lazy[node]; 
            if(a != b) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node]; 
            }
            lazy[node] = 0; 
        }
        if(a > b || a > j || b < i)
            return;
        if(a >= i && b <= j) {
            tree[node] += value;
            if(a != b) { 
                lazy[node*2] += value;
                lazy[node*2+1] += value;
            }
            return;
        }
        update_tree(node*2, a, (a+b)/2, i, j, value);
        update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
        tree[node] = max(tree[node*2], tree[node*2+1]); 
    }

    int query_tree(int node, int a, int b, int i, int j) {
        if(a > b || a > j || b < i) return -1e9; 
        if(lazy[node] != 0) {
            tree[node] += lazy[node];
            if(a != b) {
                lazy[node*2] += lazy[node]; 
                lazy[node*2+1] += lazy[node]; 
            }
            lazy[node] = 0; 
        }
        if(a >= i && b <= j)
            return tree[node];
        int q1 = query_tree(node*2, a, (a+b)/2, i, j); 
        int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); 
        int res = max(q1, q2);
        return res;
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        for(int i=0; i<N; i++) arr[i] = i;
        build_tree(1, 0, N-1);
        memset(lazy, 0, sizeof lazy);
        vector<bool> ans;
        set<int> st;
        st.insert(N-1);
        for(auto &it: queries){
            if(it[0] == 1){
                int val = query_tree(1, 0, N-1, it[1], it[1]);
                int nv = *st.lower_bound(it[1]);
                update_tree(1, 0, N-1, it[1] + 1, nv, -1 * val);
                st.insert(it[1]);
            }else{
                int val = query_tree(1, 0, N-1, 0, it[1]);
                if(val >= it[2]) ans.push_back(1);
                else ans.push_back(0);
            }
        }
        return ans;
    }
};

//check prime
bool ck(int x){
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0 || x % (x / i) == 0)
            return false;
    return true;
}
//segtree

class segTree {
private:
    vector<int> seg;
    int n;

    int merge(int a, int b) {
        return (a + b) ;
    }

    int get(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return 0;
        if (l <= start && end <= r) return seg[node];
        int mid = (start + end) / 2;
        return merge(get(2 * node, start, mid, l, r), get(2 * node + 1, mid + 1, end, l, r));
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            (seg[node] += val);
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

public:
    segTree(int _n) : n(_n) {
        seg.resize(n << 2);
    }

    int query(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
};