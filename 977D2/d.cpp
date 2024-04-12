#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YA\n" : "TIDAK\n")

struct SegmentTreeNode {
    int leftmost_x;     // First x value from the left in the range
    int rightmost_x;    // Last x value from the right in the range
    bool is_increasing; // Whether the sequence in the range is strictly increasing
    bool is_empty;      // Whether the range contains any x values

    SegmentTreeNode() : leftmost_x(-1), rightmost_x(-1), is_increasing(true), is_empty(true) {}
};

class SegmentTree {
private:
    int size;
    vector<SegmentTreeNode> tree;

    void build(int node, int l, int r, const vector<int>& S) {
        if (l == r) {
            if (S[l] != 0) {
                tree[node].leftmost_x = tree[node].rightmost_x = S[l];
                tree[node].is_increasing = true;
                tree[node].is_empty = false;
            }
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, S);
        build(2 * node + 1, mid + 1, r, S);
        combine(node);
    }

    void combine(int node) {
        SegmentTreeNode& left = tree[2 * node];
        SegmentTreeNode& right = tree[2 * node + 1];
        SegmentTreeNode& current = tree[node];

        current.is_empty = left.is_empty && right.is_empty;

        current.leftmost_x = left.is_empty ? right.leftmost_x : left.leftmost_x;
        current.rightmost_x = right.is_empty ? left.rightmost_x : right.rightmost_x;

        current.is_increasing = left.is_increasing && right.is_increasing;
        if (!left.is_empty && !right.is_empty) {
            current.is_increasing &= left.rightmost_x < right.leftmost_x;
        }
    }

    void pointUpdate(int node, int l, int r, int idx, int val) {
        if (l == r) {
            if (val != 0) {
                tree[node].leftmost_x = tree[node].rightmost_x = val;
                tree[node].is_increasing = true;
                tree[node].is_empty = false;
            } else {
                tree[node] = SegmentTreeNode();
            }
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            pointUpdate(2 * node, l, mid, idx, val);
        else
            pointUpdate(2 * node + 1, mid + 1, r, idx, val);
        combine(node);
    }

public:
    SegmentTree(int n) : size(n) {
        tree.resize(4 * n + 4);
    }

    void build(const vector<int>& S) {
        build(1, 0, size - 1, S);
    }

    void pointUpdate(int idx, int val) {
        pointUpdate(1, 0, size - 1, idx, val);
    }

    bool isIncreasing() {
        return tree[1].is_increasing;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, Q;
    cin >> n >> Q;

    vector<int> A(n);
    unordered_map<int, set<int>> positions;
    vector<int> first_occurrence(n + 1, n + 1);
    vector<int> S(n, 0); // S[i] stores x value at position i (0-based indexing)

    // Read the array and initialize positions
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        positions[A[i]].insert(i);
    }

    // Initialize first_occurrence and S
    for (int x = 1; x <= n; ++x) {
        if (!positions[x].empty()) {
            first_occurrence[x] = *positions[x].begin();
            S[first_occurrence[x]] = x;
        }
    }

    // Build the segment tree
    SegmentTree segTree(n);
    segTree.build(S);

    // Output the initial result
    cout << (segTree.isIncreasing() ? "Yes\n" : "No\n");

    // Process queries
    for (int q = 0; q < Q; ++q) {
        int idx, new_value;
        cin >> idx >> new_value;
        --idx;  // Convert to 0-based indexing

        int old_value = A[idx];

        if (old_value == new_value) {
            // No change needed
            cout << (segTree.isIncreasing() ? "Yes\n" : "No\n");
            continue;
        }

        // Remove idx from positions[old_value]
        positions[old_value].erase(idx);

        // Update first_occurrence[old_value] if needed
        if (first_occurrence[old_value] == idx) {
            // Remove old_value from S
            segTree.pointUpdate(idx, 0);
            S[idx] = 0;

            if (!positions[old_value].empty()) {
                int new_pos = *positions[old_value].begin();
                first_occurrence[old_value] = new_pos;
                S[new_pos] = old_value;
                segTree.pointUpdate(new_pos, old_value);
            } else {
                first_occurrence[old_value] = n + 1;
            }
        }

        // Add idx to positions[new_value]
        bool was_new_value_absent = positions[new_value].empty();
        positions[new_value].insert(idx);

        // Update first_occurrence[new_value] if needed
        if (first_occurrence[new_value] > idx) {
            if (first_occurrence[new_value] <= n) {
                // Remove new_value from its old position in S
                int old_pos = first_occurrence[new_value];
                segTree.pointUpdate(old_pos, 0);
                S[old_pos] = 0;
            }
            first_occurrence[new_value] = idx;
            S[idx] = new_value;
            segTree.pointUpdate(idx, new_value);
        }

        A[idx] = new_value;

        // Output the result
        cout << (segTree.isIncreasing() ? "Yes\n" : "No\n");
    }
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
