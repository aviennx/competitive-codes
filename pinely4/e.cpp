#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define vi vector<int>
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define int long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;


     
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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i : a)
        cin >> i;
    auto arr = manacher(a);
    //for(int i : arr[0])
    //    cout << i << " ";
    //cout << '\n';
    //for(int i : arr[1])
    //    cout << i << " ";
    //cout << '\n';
    vector<int> p(n, 0);
    for(int i = 0; i < n; i++){
        p[i] = a[i];
        if(i)
            p[i] += p[i - 1];
        p[i] %= mod;
    }
    vector<int> q(n, 0);
    for(int i = 0; i < n; i++){
        q[i] = p[i];
        if(i)
            q[i] += q[i - 1];
        q[i] %= mod;
    }
    Mint ans = 0;
    for(int i = 0; i < n; i++){
        //cout << q[i] << " ";
        int odd = arr[1][i];
        int even = arr[0][i];
        int x = odd;
        ans += q[i + x];
        //ans %= mod;

        if(i - 1 >= 0)
            ans -= 2 * (q[ i - 1]);
        //ans %= mod;
        if(i - 2 - x >= 0)
            ans += q[i - 2 - x];
        //ans %= mod;

        x = even;
        if(even){
            ans += q[i + x - 1];
            //ans %= mod;

            if(i - 1 >= 0)
                ans -= q[ i - 1];
            //ans %= mod;

            if(i - 2 >= 0)
                ans -= q[ i - 2];
            //ans %= mod;

            if(i - 2 - x >= 0)
                ans += q[i - 2 - x];
            //ans %= mod;

        }
    }
    //cout << '\n';
    cout << ans << '\n';

    
    

}


int32_t main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
