class Solution {
public:

    struct Node {
        int prod;
        long long cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };

    int k;
    int n;
    vector<Node> tree;

    Node merge(Node left, Node right) {
        Node result;

        // Product of the whole combined segment
        result.prod = (left.prod * right.prod) % k;

        // Prefixes that are completely inside the left segment
        for (int r = 0; r < k; r++) {
            result.cnt[r] += left.cnt[r];
        }

        // Prefixes that use the entire left segment
        // and then continue into the right segment
        for (int r = 0; r < k; r++) {
            int newRemainder = (left.prod * r) % k;
            result.cnt[newRemainder] += right.cnt[r];
        }

        return result;
    }

    void build(vector<int>& nums, int node, int left, int right) {

        if (left == right) {
            int value = nums[left] % k;

            tree[node].prod = value;
            tree[node].cnt[value] = 1;

            return;
        }

        int mid = left + (right - left) / 2;

        build(nums, node * 2, left, mid);
        build(nums, node * 2 + 1, mid + 1, right);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int left, int right,
                int index, int value) {

        if (left == right) {
            value %= k;

            tree[node].prod = value;

            for (int r = 0; r < k; r++) {
                tree[node].cnt[r] = 0;
            }

            tree[node].cnt[value] = 1;

            return;
        }

        int mid = left + (right - left) / 2;

        if (index <= mid) {
            update(node * 2, left, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, right, index, value);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    Node query(int node, int left, int right,
               int ql, int qr) {

        // Completely inside requested range
        if (ql <= left && right <= qr) {
            return tree[node];
        }

        int mid = left + (right - left) / 2;

        // Query is completely in right half
        if (ql > mid) {
            return query(node * 2 + 1,
                         mid + 1,
                         right,
                         ql,
                         qr);
        }

        // Query is completely in left half
        if (qr <= mid) {
            return query(node * 2,
                         left,
                         mid,
                         ql,
                         qr);
        }

        // Query overlaps both halves
        Node leftResult = query(node * 2,
                                left,
                                mid,
                                ql,
                                qr);

        Node rightResult = query(node * 2 + 1,
                                 mid + 1,
                                 right,
                                 ql,
                                 qr);

        return merge(leftResult, rightResult);
    }

    vector<int> resultArray(vector<int>& nums, int k,vector<vector<int>>& queries) {

        this->k = k;
        this->n = nums.size();

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> answer;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // Get information about nums[start ... n-1]
            Node result = query(1,
                                0,
                                n - 1,
                                start,
                                n - 1);

            answer.push_back(result.cnt[x]);
        }

        return answer;
    }
};