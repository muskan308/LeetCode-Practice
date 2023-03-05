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
    
    bool ans(TreeNode *root, TreeNode *target, vector<TreeNode*> &arr){
        if(root==NULL)return false;
        if(root==target){
            arr.push_back(root);
            return true;
        }
        if(ans(root->left, target, arr) || ans(root->right, target, arr)){
            arr.push_back(root);
            return true;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1, arr2;
        
        ans(root, p, arr1);
        ans(root, q, arr2);
        
        int i = arr1.size()-1, j = arr2.size()-1;
        // cout << i << " "<<j;
        while(i>=0 && j>=0){
            if(i == 0) return arr1[i];
            if(j == 0) return arr2[j];
            if(arr1[i-1]->val != arr2[j-1]->val)return arr1[i];
            i--;j--;
        }
        return NULL;
    }
};