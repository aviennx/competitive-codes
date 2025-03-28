Prime counter // 

    vector<ll> isprime(N, 1), lp(N);
    for(ll i=2;i<N;i++) {
        if(isprime[i]==0)   
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
