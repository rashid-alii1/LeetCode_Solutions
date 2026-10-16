class Solution {
private:
    static const int MOD = 1'000'000'007;

    struct Node {
        long long sum = 0;
        long long sumSq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    // Apply an increment to an entire segment.
    void apply(int node, int left, int right, long long val) {
        long long len = right - left + 1;

        tree[node].sumSq =
            (tree[node].sumSq
             + 2 * val % MOD * tree[node].sum % MOD
             + val * val % MOD * len % MOD) % MOD;

        tree[node].sum =
            (tree[node].sum + val * len) % MOD;

        tree[node].lazy =
            (tree[node].lazy + val) % MOD;
    }

    // Pass pending updates to the children.
    void push(int node, int left, int right) {
        if (tree[node].lazy == 0 || left == right)
            return;

        int mid = left + (right - left) / 2;

        apply(node * 2, left, mid, tree[node].lazy);

        apply(node * 2 + 1, mid + 1, right,
              tree[node].lazy);

        tree[node].lazy = 0;
    }

    // Increase all positions in the query range.
    void update(int node, int left, int right,
                int ql, int qr, long long val) {
        if (qr < left || right < ql)
            return;

        if (ql <= left && right <= qr) {
            apply(node, left, right, val);
            return;
        }

        push(node, left, right);

        int mid = left + (right - left) / 2;

        update(node * 2, left, mid, ql, qr, val);

        update(node * 2 + 1, mid + 1, right,
               ql, qr, val);

        tree[node].sum =
            (tree[node * 2].sum +
             tree[node * 2 + 1].sum) % MOD;

        tree[node].sumSq =
            (tree[node * 2].sumSq +
             tree[node * 2 + 1].sumSq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node{});

        vector<int> last(100001, -1);
        long long answer = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];

            update(1, 0, n - 1, prev + 1, i, 1);

            answer = (answer + tree[1].sumSq) % MOD;

            last[nums[i]] = i;
        }

        return static_cast<int>(answer);
    }
};