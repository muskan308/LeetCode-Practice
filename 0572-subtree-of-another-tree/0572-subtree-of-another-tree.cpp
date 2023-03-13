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
    
    bool com(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL || root2 ==NULL) return root1 == NULL && root2 == NULL;
        if(root1->val != root2->val) return false;
       bool l = com(root1->left, root2->left);
        bool r = com(root1->right, root2->right);
        return l && r;
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         if(root==NULL) return false;
        if(com(root, subRoot)){
            return true ;
        }
       
        
        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);
        return l||r;
    }
};