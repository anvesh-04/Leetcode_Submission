#include <vector>

using namespace std;

class Solution {
    vector<long long> tree_sq;
    vector<long long> tree_c;
    vector<long long> lazy;
    const int MOD = 1e9 + 7;

    void push_down(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = l + (r - l) / 2;
            long long len_left = mid - l + 1;
            long long len_right = r - mid;
            long long val = lazy[node];

            // Update left child
            tree_sq[2 * node] = (tree_sq[2 * node] + 2 * val * tree_c[2 * node] + val * val % MOD * len_left) % MOD;
            tree_c[2 * node] = (tree_c[2 * node] + val * len_left) % MOD;
            lazy[2 * node] = (lazy[2 * node] + val) % MOD;

            // Update right child
            tree_sq[2 * node + 1] = (tree_sq[2 * node + 1] + 2 * val * tree_c[2 * node + 1] + val * val % MOD * len_right) % MOD;
            tree_c[2 * node + 1] = (tree_c[2 * node + 1] + val * len_right) % MOD;
            lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % MOD;

            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            long long len = r - l + 1;
            tree_sq[node] = (tree_sq[node] + 2 * tree_c[node] + len) % MOD;
            tree_c[node] = (tree_c[node] + len) % MOD;
            lazy[node] = (lazy[node] + 1) % MOD;
            return;
        }

        push_down(node, l, r);
        int mid = l + (r - l) / 2;
        
        if (ql <= mid) update(2 * node, l, mid, ql, qr);
        if (qr > mid) update(2 * node + 1, mid + 1, r, ql, qr);

        tree_sq[node] = (tree_sq[2 * node] + tree_sq[2 * node + 1]) % MOD;
        tree_c[node] = (tree_c[2 * node] + tree_c[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        
        tree_sq.assign(4 * n, 0);
        tree_c.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        // Optimized from unordered_map since max value in nums is 10^5
        vector<int> last_seen(100001, -1);
        long long total_sum = 0;

        for (int i = 0; i < n; i++) {
            int start = last_seen[nums[i]] + 1;
            
            update(1, 0, n - 1, start, i);
            total_sum = (total_sum + tree_sq[1]) % MOD;
            
            last_seen[nums[i]] = i;
        }

        return total_sum;
    }
};