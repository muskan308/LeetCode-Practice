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
    
    TreeNode *solve(vector<int> &postorder, int &postIndex, int left, int right, map<int, int> &mp){
        if(left > right) return NULL;
        int ele = postorder[postIndex--];
        TreeNode *root = new TreeNode(ele);
        int pos = mp[ele];
        root->right = solve(postorder, postIndex, pos+1, right, mp);
        root->left = solve(postorder, postIndex, left, pos-1, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postIndex = n-1;
        map<int, int> positions;
        for(int i = 0 ; i <  n ; i++){
            positions[inorder[i]] = i;
        }
        TreeNode *root = solve(postorder, postIndex, 0, n-1, positions);
        return root;
    }
};