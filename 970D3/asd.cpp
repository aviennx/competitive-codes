#include <bits/stdc++.h>
using namespace std;

// Define constants and utility functions
#define pb push_back
#define ll long long
#define cpsolve_yes cout << "YES"
#define cpsolve_no cout << "NO"
#define cpsolve_nl "\n"
#define cpsolve_loop(i, n) for (int cpsolve_i = 0; cpsolve_i < (int)n; cpsolve_i++)
#define cpsolve_loop1(i, n) for (int cpsolve_i = 1; cpsolve_i <= (int)n; cpsolve_i++)
#define cpsolve_loopab(i, a, b) for (int cpsolve_i = (int)a; cpsolve_i <= (int)b; cpsolve_i++)
#define cpsolve_all(a) (a).begin(), (a).end()

ll cpsolve_MOD = 1e9 + 7;
int gcd(int x, int y){
    if (x < y) swap(x, y);
    while (x > y && y != 0){
        x %= y;
        swap(x, y);
    }
    return x;
}
// Function to find the k-th missing positive integer
int cpsolve_findKthMissingPositive(vector<ll> &cpsolve_arr, ll cpsolve_k) {
    // If the first element in the array is greater than cpsolve_k,
    // the cpsolve_kth missing number must be cpsolve_k itself.
    if (cpsolve_arr[0] > cpsolve_k) {
        return cpsolve_k;
    }

    int cpsolve_left = 0;
    int cpsolve_right = cpsolve_arr.size();

    while (cpsolve_left < cpsolve_right) {
        int cpsolve_mid = cpsolve_left + (cpsolve_right - cpsolve_left) / 2;

        if (cpsolve_arr[cpsolve_mid] - cpsolve_mid - 1 >= cpsolve_k) {
            cpsolve_right = cpsolve_mid;
        } else {
            cpsolve_left = cpsolve_mid + 1;
        }
    }

    return cpsolve_arr[cpsolve_left - 1] + cpsolve_k - (cpsolve_arr[cpsolve_left - 1] - (cpsolve_left - 1) - 1);
}

// Main function to solve the problem
void cpsolve_solve() {
    ll cpsolve_n, cpsolve_k;
    cin >> cpsolve_n >> cpsolve_k;
    vector<ll> cpsolve_a(cpsolve_n);
    cpsolve_loop(cpsolve_i, cpsolve_n) cin >> cpsolve_a[cpsolve_i];
    sort(cpsolve_a.begin(), cpsolve_a.end(), greater<ll>());

    if (cpsolve_a[0] == 0) {
        cout << cpsolve_k << cpsolve_nl;
        return;
    }

    if (cpsolve_n == 1) {
        cout << cpsolve_findKthMissingPositive(cpsolve_a, cpsolve_k - 1) << cpsolve_nl;
        return;
    }

    ll cpsolve_gc = cpsolve_a[0];
    cpsolve_loop(cpsolve_i, cpsolve_n) {
        cpsolve_gc = gcd(cpsolve_gc, cpsolve_a[cpsolve_i]);
    }

    ll cpsolve_im = 0;
    cpsolve_loop(cpsolve_i, cpsolve_n) {
        cpsolve_a[cpsolve_i] = cpsolve_im * cpsolve_gc;
        cpsolve_im++;
    }

    ll cpsolve_ans = cpsolve_findKthMissingPositive(cpsolve_a, cpsolve_k - 1);
    cout << cpsolve_ans << cpsolve_nl;
}

int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    ll cpsolve_t = 1;
    cin >> cpsolve_t;
    while (cpsolve_t--) {
        cpsolve_solve();
    }
    return 0;
}

