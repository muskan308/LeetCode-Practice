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
     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> st1, st2;
        vector<vector<int>> ans;
        
        st1.push(root);
        while(!st1.empty() || !st2.empty()){
            vector<int> a;
            int s1 = st1.size();
            while(!st1.empty()){
                TreeNode* v = st1.top();
                st1.pop();
                if(v->left) st2.push(v->left);
                if(v->right) st2.push(v->right);
                a.push_back(v->val);
            }
            if(a.size() > 0)  ans.push_back(a);
            a= {};
            while(!st2.empty()){
                TreeNode* v = st2.top();
                st2.pop();
                if(v->right) st1.push(v->right);
                if(v->left) st1.push(v->left);
                a.push_back(v->val);
            }
            if(a.size() > 0) ans.push_back(a);
        }
        return ans;
    }
};