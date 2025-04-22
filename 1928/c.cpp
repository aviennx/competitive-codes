#include <iostream>
#include <unordered_set>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    
    int a = n - x, b = n + x - 2;
    unordered_set<int> st;
 
    int mn = x * 2 - 2;
    for(int i = 1; i * i <= a; ++i){
        if(a % i == 0){
            if(i % 2 == 0 && i >= mn)
                st.insert(i);
            if((a / i) % 2 == 0 && a / i >= mn) st.insert(a / i);
        }
    }
 
    for(int i = 1; i * i <= b; ++i){
        if(b % i == 0){
            if(i % 2 == 0 && i >= mn)
                st.insert(i);
            if((b / i) % 2 == 0 && b / i >= mn) st.insert(b / i);
        }
    }
    cout << (int)st.size() << endl;
}

int main() {
    //reopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}
