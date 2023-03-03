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
    
    TreeNode *solve(vector<int> pre, int &preIndex, int startIn, int endIn, map<int, int> &mp){
        if(startIn > endIn){
            return NULL;
        }
        int element = pre[preIndex++];
        TreeNode *root = new TreeNode(element);
        int pos = mp[element];
        root->left = solve(pre, preIndex, startIn, pos-1, mp);
        root->right = solve(pre, preIndex, pos+1, endIn, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n= in.size();
        map<int, int> mp;
        for(int i = 0; i < n ; i++){
            mp[in[i]] = i;
        }
        int preIndex = 0;
        TreeNode * ans = solve(pre, preIndex, 0, n-1, mp);
        return ans;
    }
};