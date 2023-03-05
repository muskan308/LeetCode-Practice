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
    map<TreeNode*, int> heights;
    int height(TreeNode *root){
        if(root==NULL)return heights[root]=0;
        
        return heights[root] = 1+ max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        height(root);
        
        int h1 = heights[root->left];
        int h2 = heights[root->right];
        return max(h1+h2, max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right) ));
    }
};