class Solution {
public:
    #define MAXN 50000
    vector<int> nums;
    int N, tree[4 * MAXN];

    void buildTree(int s, int e, int v) {
        if (s == e) {
            tree[v] = nums[s];
            return;
        }
        int mid = (s + e) / 2;
        buildTree(s, mid, 2 * v + 1);
        buildTree(mid + 1, e, 2 * v + 2);
        tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    }

    int query(int s, int e, int v, int x, int i) {
        if (s == e)
          return tree[v] > x && s >= i ? s : -1;
        int mid = (s + e) / 2;
        if (tree[2 * v + 1] > x && mid >= i) {
            int q = query(s, mid, 2 * v + 1, x, i);
            if (q != -1)
              return q;
        }
        return query(mid + 1, e, 2 * v + 2, x, i);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        N = heights.size(); nums = heights;
        buildTree(0, N - 1, 0);
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] > queries[i][1]) swap(queries[i][0], queries[i][1]);
            if (nums[queries[i][1]] > nums[queries[i][0]] || queries[i][1] == queries[i][0])
              ans[i] = queries[i][1];
            else 
              ans[i] = query(0, N - 1, 0, nums[queries[i][0]], queries[i][1]);
        }
        return ans;
    }
};