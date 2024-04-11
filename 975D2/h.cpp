#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) | 1)
    vector<long long> t, lazy;

    ST(int N = 0) {
        t.resize(4 * N + 5);
        lazy.resize(4 * N + 5);
        for(int i = 0; i <= 4 * N; i++) t[i] = lazy[i] = 0;
    }
     
  inline void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    if (b != e) {
      lazy[lc] = lazy[lc] + lazy[n];
      lazy[rc] = lazy[rc] + lazy[n];
      t[lc] += lazy[n];
      t[rc] += lazy[n];
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a,long long b) {
    min(a, b);
  }
  inline void pull(int n) {
    t[n] = min(t[lc], t[rc]);
  }
  void upd(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] += v; //set lazy
      t[n] += v;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
};

int main() {
   int t; cin >> t;
   while(t--) {
    int n; cin >> n;
    ST S = ST(n + 3);
    vector<int> a(n + 5, 0);
    vector<int> le(n + 5), ri(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    le[0] = ri[n + 1] = 1e9;
    for(int i = 1; i <= n; i++) {
        le[i] = min(a[i], le[i - 1] - 1);
        le[i] = max(le[i], 0);
    }
    for(int i = n; i >= 1; i--) {
        ri[i] = min(a[i], ri[i + 1] - 1);
        ri[i] = max(ri[i], 0);
    }


    int answer = 0;
    for(int i = 1; i <= n; i++) S.upd(1, 0, n, i, i, i - n - 1);
    for(int i = 2; i <= n; i++) S.upd(1, 0, n, 0, ri[i], 1);
    for(int i = 1; i <= n; i++) {
        S.upd(1, 0, n, 0, 1, 1);
        if(S.t[1] >= 0) answer++;
        if(i < n) S.upd(1, 0, n, 0, ri[i + 1], -1);
        S.upd(1, 0, n, 0, le[i], 1);
        S.upd(1, 0, n, 0, 1, -1);
    }
    cout << answer << '\n';
   }
}
