/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* ans(TreeNode *root, TreeNode *q, TreeNode *p){
        
        if(!root || root==q|| root==p)return root;
        TreeNode *l = ans(root->left, q, p);
        TreeNode *r = ans(root->right, q, p);
        bool curr = (root == q || root==p);
        if(curr && (l || r)) return root;
        return (!l ? r : !r ? l : root);
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return ans(root, p,q);
        
        
    }
};