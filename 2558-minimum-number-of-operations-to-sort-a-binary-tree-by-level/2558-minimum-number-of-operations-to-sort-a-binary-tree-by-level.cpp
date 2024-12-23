/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimum_swaps(vector<int>&arr,int n){
        vector<pair<int,int>>vec(n);
        for(int i = 0;i < n;i++){
            vec[i] = {arr[i],i};
        }
        sort(vec.begin(),vec.end());
        vector<bool>vis(n);
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(vis[i]==true || vec[i].second==i){
                vis[i] = true;
            }
            else{
                int cycle_size = 0;
                int j = i;
                do{
                    vis[j] = true;
                    j = vec[j].second;
                    cycle_size++;
                }
                while(j!=i);
                if(cycle_size>1)ans += (cycle_size-1);
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root){
            return 0;
        }
        else{
            int ans = 0;
            q.push(root);
            while(!q.empty()){
                int n = q.size();
                vector<int>vec(n);
                for(int i = 0;i < n;i++){
                    TreeNode* node = q.front();
                    q.pop();
                    vec[i] = node->val;
                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);
                }
                int currans = minimum_swaps(vec,n);
                ans += minimum_swaps(vec,n);
            }
            return ans;
        }
    }
};