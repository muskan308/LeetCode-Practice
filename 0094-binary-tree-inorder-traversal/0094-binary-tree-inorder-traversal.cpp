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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        unordered_set<TreeNode*> visited;
        while(!st.empty()){
            TreeNode* top = st.top();
            // st.pop();
            
            if(top->left && (visited.count(top->left) == 0)){
                // st.push(top);
                st.push(top->left);
                visited.insert(top->left);
                continue;
            }else{
                st.pop();
                ans.push_back(top->val);
            }
            if(top->right) {
                st.push(top->right);
                
            }            
        }
        return ans;
    }
};