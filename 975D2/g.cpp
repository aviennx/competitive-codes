#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Segment Tree with Lazy Propagation
template<typename T>
class SegmentTree {
private:
    int size;
    vector<T> tree; // The segment tree
    vector<T> lazy; // Lazy propagation array

    // Get the left child index
    inline int leftChild(int node) {
        return node << 1;
    }

    // Get the right child index
    inline int rightChild(int node) {
        return (node << 1) | 1;
    }

    // Push the lazy updates down the tree
    void push(int node, int left, int right) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (left != right) { // Not a leaf node
                lazy[leftChild(node)] += lazy[node];
                lazy[rightChild(node)] += lazy[node];
            }
            lazy[node] = 0; // Reset the lazy value
        }
    }

    // Combine function for the segment tree (minimum in this case)
    T combine(T a, T b) {
        return min(a, b);
    }

    // Pull up the values after updates
    void pull(int node) {
        tree[node] = combine(tree[leftChild(node)], tree[rightChild(node)]);
    }

    // Internal update function for range updates
    void update(int node, int left, int right, int l, int r, T value) {
        push(node, left, right);
        if (r < left || right < l) return; // No overlap
        if (l <= left && right <= r) {     // Total overlap
            lazy[node] += value;
            push(node, left, right);
            return;
        }
        // Partial overlap
        int mid = (left + right) / 2;
        update(leftChild(node), left, mid, l, r, value);
        update(rightChild(node), mid + 1, right, l, r, value);
        pull(node);
    }

    // Internal query function for range queries
    T query(int node, int left, int right, int l, int r) {
        push(node, left, right);
        if (r < left || right < l) return numeric_limits<T>::max(); // Return maximum possible value for min function
        if (l <= left && right <= r) return tree[node];             // Total overlap
        // Partial overlap
        int mid = (left + right) / 2;
        return combine(
            query(leftChild(node), left, mid, l, r),
            query(rightChild(node), mid + 1, right, l, r)
        );
    }

public:
    // Constructor to initialize the segment tree
    SegmentTree(int n) {
        size = n;
        tree.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
    }

    // Public function to perform range updates
    void update(int l, int r, T value) {
        update(1, 0, size - 1, l, r, value);
    }

    // Public function to perform range queries
    T query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }

    // Query the entire range
    T queryAll() {
        push(1, 0, size - 1);
        return tree[1];
    }
};

int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Initialize the segment tree with size n + 3
        SegmentTree<long long> segTree(n + 3);

        vector<int> a(n + 5, 0); // Input array (1-indexed)
        vector<int> le(n + 5);   // Left constraints
        vector<int> ri(n + 5);   // Right constraints

        // Read the input array
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        le[0] = ri[n + 1] = 1e9; // Initialize boundaries

        // Compute the 'le' array (left constraints)
        for (int i = 1; i <= n; i++) {
            le[i] = min(a[i], le[i - 1] - 1);
            le[i] = max(le[i], 0); // Ensure non-negative
        }

        // Compute the 'ri' array (right constraints)
        for (int i = n; i >= 1; i--) {
            ri[i] = min(a[i], ri[i + 1] - 1);
            ri[i] = max(ri[i], 0); // Ensure non-negative
        }

        int answer = 0;

        // Initialize the segment tree with initial values
        for (int i = 1; i <= n; i++)
            segTree.update(i, i, i - n - 1);

        // Update the segment tree based on 'ri' values
        for (int i = 2; i <= n; i++)
            segTree.update(0, ri[i], 1);

        // Process each position
        for (int i = 1; i <= n; i++) {
            segTree.update(0, 1, 1);
            if (segTree.queryAll() >= 0)
                answer++;
            if (i < n)
                segTree.update(0, ri[i + 1], -1);
            segTree.update(0, le[i], 1);
            segTree.update(0, 1, -1);
        }

        // Output the result
        cout << answer << '\n';
    }
    return 0;
}