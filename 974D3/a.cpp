#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define yesno(x) cout << ((x) ? "YES" : "NO")

using namespace std;
typedef __int128 int128_t;
// Function to convert a string to a 128-bit integer
int128_t str_to_int128(const std::string& s) {
    int128_t result = 0;
    for (char c : s) {
        result = result * 10 + (c - '0');
    }
    return result;
}

// Function to read a 128-bit integer from standard input
int128_t read_int128() {
    std::string s;
    std::cin >> s;
    return str_to_int128(s);
}

// Function to print a 128-bit integer to standard output
void print_int128(int128_t n) {
    if (n == 0) {
        std::cout << '0';
        return;
    }
    std::string s;
    bool is_negative = false;
    if (n < 0) {
        is_negative = true;
        n = -n;
    }
    while (n > 0) {
        s.push_back('0' + n % 10);
        n /= 10;
    }
    if (is_negative) {
        s.push_back('-');
    }
    std::reverse(s.begin(), s.end());
    std::cout << s;
}

// Main function to find the Kth character after all operations
char findKthCharacter(const std::string& initial_S, const std::vector<int>& operations, int128_t K) {
    int N = operations.size();
    std::vector<int128_t> len_S_list(N + 1);
    len_S_list[0] = initial_S.length();

    // Precompute the lengths after each operation
    for (int i = 1; i <= N; ++i) {
        len_S_list[i] = len_S_list[i - 1] * 2;
    }

    int n = N;
    int shift_count = 0;

    // Recursive logic to find the original character position and total shifts
    while (n > 0) {
        int128_t L_n_minus_1 = len_S_list[n - 1];
        if (K <= L_n_minus_1) {
            n -= 1;
        } else {
            K -= L_n_minus_1;
            if (operations[n - 1] == 1) {
                shift_count += 1;
            }
            n -= 1;
        }
    }

    // Calculate the final character after applying shifts
    char ch = initial_S[(int)(K - 1)];
    int total_shift = shift_count % 26;
    char result_char = ((ch - 'a' + total_shift) % 26) + 'a';
    return result_char;
}

int main() {
    // Read the initial string S
    std::string initial_S;
    std::cin >> initial_S;
    int n;
    cin >> n;
    // Read the operations (array of size 100)
    std::vector<int> operations(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> operations[i];
    }

    // Read the integer K
    int128_t K = read_int128();

    // Find and output the Kth character after all operations
    char result_char = findKthCharacter(initial_S, operations, K);
    std::cout << result_char << std::endl;

    return 0;
}