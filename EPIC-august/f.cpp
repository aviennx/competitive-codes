#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define sz(s) (int)s.size()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define maxn 500005
mt19937 Rand(chrono::steady_clock::now().time_since_epoch().count());
int read() {
    int x = 0, w = 0; char ch = getchar();
    while(!isdigit(ch)) w |= ch == '-', ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return w ? -x : x;
}
int n, Q, fa[maxn], p[maxn], q[maxn], siz[maxn];
set<int> son[maxn];
int chk(int x) {
    cout << x << " : ";
    return son[x].empty() ? 1 : (q[x] < *son[x].begin() && *--son[x].end() + siz[p[*--son[x].end()]] <= q[x] + siz[x]);
}
void solve() {
    scanf("%d", &n);

        for (int i = 1; i <= n; ++i)
            scanf("%lld%d", a + i, b + i);

        sn = 0;
        ll x = 0;

        for (int i = 1; i <= n; ++i) {
            ll mx = 0;

            while (sn) {
                if (s[sn].s2 == b[i])
                    a[i] += s[sn--].s1 - mx;
                else if (s[sn].s1 <= a[i])
                    mx = max(mx, s[sn--].s1);
                else
                    break;
            }

            ++sn;
            s[sn] = pii(a[i], b[i]);
            x = max(x, s[sn].s1);
            printf("%lld ", x);
        }

}
int main() {
     freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int T = read();
    while(T--) solve();
    return 0;
}