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


// sort index array // 

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



// debug array //
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

// sort //

sort(tasks.begin(),tasks.end(),[](const auto& a,const auto& b){
            return a[1]<b[1];
        });


//getprime //

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


// check bipartite // 
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

//---binary jumping--//


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



//-------------   Segment Tree ----------//


struct ap {
    int base, dif;
};

ap add(ap a, ap b)
{
    ap res;
    res.base = a.base + b.base;
    res.dif = a.dif + b.dif;
    return res;
}

int convert(ap a, int n)
{
    int res = (n*a.base);
    res += ((n*(n-1))/2ll)*a.dif;
    return res;
}

int st[4*N], cost[N];
ap lazy[4*N];
ap zero = {0, 0};

void propogate(int node, int l, int r)
{
    st[node] += convert(lazy[node], r-l+1);
    if(l!=r)
    {
        lazy[node*2+1] = add(lazy[node*2+1], lazy[node]);
        int mid = (l+r)/2;
        int rig = (r-mid);
        lazy[node].base += (rig*lazy[node].dif);
        lazy[node*2] = add(lazy[node*2], lazy[node]);
    }
    lazy[node] = zero;
}
void build(int node, int l, int r)
{
    if(l==r)
    {
        st[node] = cost[l];
        lazy[node] = zero;
        return;
    }
    int mid=(l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    st[node] = (st[node*2] + st[node*2+1]);
    lazy[node] = zero; 
    return;
}
void update(int node, int l, int r, int x, int y, ap val)
{
    if(lazy[node].base != 0 || lazy[node].dif != 0)
    propogate(node, l, r);
    if(y<x||x>r||y<l)
    return;
    if(l>=x&&r<=y)
    {
        st[node] += convert(val, r-l+1);
        if(l!=r)
        {
            lazy[node*2+1] = add(lazy[node*2+1], val);
            int mid = (l+r)/2;
            int rig = (r-mid);
            val.base += (rig*val.dif);
            lazy[node*2] = add(lazy[node*2], val);
        }
        return;
    }
    int mid=(l+r)/2;
    update(node*2+1, mid+1, r, x, y, val);
    if(y>mid)
    {
        int rig = (min(y, r)-mid);
        val.base += (rig*val.dif);
    }
    update(node*2, l, mid, x, y, val);
    st[node] = st[node*2] + st[node*2+1];
    return;
}
int query(int node, int l, int r, int x, int y)
{
    if(lazy[node].base != 0 || lazy[node].dif != 0)
    propogate(node, l, r);
    if(y<x||y<l||x>r)
    return 0;
    if(l>=x&&r<=y)
    return st[node];
    int mid=(l+r)/2;
    return query(node*2, l, mid, x, y) + query(node*2+1, mid+1, r, x, y);
}

//--------------///