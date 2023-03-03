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
    int preIndex;
    map<int, int> mp;
    TreeNode *solve(vector<int> pre, int startIn, int endIn){
        if(startIn > endIn){
            return NULL;
        }
        int element = pre[preIndex++];
        TreeNode *root = new TreeNode(element);
        int pos = mp[element];
        root->left = solve(pre, startIn, pos-1);
        root->right = solve(pre, pos+1, endIn);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n= in.size();
        
        for(int i = 0; i < n ; i++){
            mp[in[i]] = i;
        }
        preIndex = 0;
        TreeNode * ans = solve(pre, 0, n-1);
        return ans;
    }
};