
#include <vector>
#include <string>
#include <sstream>
#include <array>
#include <algorithm>
#include <tuple>
using namespace std;

class Solution {
    static constexpr int LOG = 17;

    int n;
    int timer = 0;

    vector<vector<int>> adj;
    vector<array<int, LOG>> up;
    vector<int> depth, tin, tout;
    vector<int> baseMask;

    // Fenwick Tree supporting XOR updates and prefix XOR queries
    vector<int> bit;

    void add(int idx, int value) {
        while (idx <= n + 1) {
            bit[idx] ^= value;
            idx += idx & -idx;
        }
    }

    int prefixXor(int idx) {
        int result = 0;

        while (idx > 0) {
            result ^= bit[idx];
            idx -= idx & -idx;
        }

        return result;
    }

    // XOR-update every node in subtree u
    void updateSubtree(int u, int value) {
        add(tin[u] + 1, value);
        add(tout[u] + 2, value);
    }

    // Current XOR mask from root to u, inclusive
    int rootMask(int u) {
        return baseMask[u] ^ prefixXor(tin[u] + 1);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int k = LOG - 1; k >= 0; k--) {
            if (diff & (1 << k))
                u = up[u][k];
        }

        if (u == v)
            return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[u][k] != up[v][k]) {
                u = up[u][k];
                v = up[v][k];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(
    int n,
    vector<vector<int>>& edges,
    string s,
    vector<string>& queries
    )
    {
        this->n = n;
        timer = 0;

        adj.assign(n, {});
        up.assign(n, {});
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        baseMask.assign(n, 0);
        bit.assign(n + 2, 0);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Iterative DFS with entry and exit events
        vector<tuple<int, int, int>> st;
        st.push_back({0, 0, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 1) {
                tout[u] = timer - 1;
                continue;
            }

            tin[u] = timer++;

            up[u][0] = p;
            for (int k = 1; k < LOG; k++) {
                up[u][k] = up[up[u][k - 1]][k - 1];
            }

            if (u != 0)
                depth[u] = depth[p] + 1;

            int ownBit = 1 << (s[u] - 'a');
            baseMask[u] =
                (u == 0 ? 0 : baseMask[p]) ^ ownBit;

            st.push_back({u, p, 1});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];

                if (v != p) {
                    st.push_back({v, u, 0});
                }
            }
        }

        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                int oldBit = 1 << (s[u] - 'a');
                int newBit = 1 << (c - 'a');
                int delta = oldBit ^ newBit;

                if (delta != 0) {
                    updateSubtree(u, delta);
                    s[u] = c;
                }
            } else {
                int u, v;
                ss >> u >> v;

                int w = lca(u, v);

                int mask = rootMask(u)
                         ^ rootMask(v)
                         ^ (1 << (s[w] - 'a'));

                // At most one character has odd frequency
                answer.push_back(
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return answer;
    }
};
