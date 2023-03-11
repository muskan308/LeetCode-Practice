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
    
    int height(TreeNode* root){
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }
   
    int rheight(TreeNode* root){
        if(root==NULL)return 0;
        return 1 + rheight(root->right);
    }
     int lheight(TreeNode* root){
        if(root==NULL)return 0;
        return 1 + lheight(root->left);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        if(lheight(root) == rheight(root)){
            int h = height(root);
            return pow(2,h)-1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};