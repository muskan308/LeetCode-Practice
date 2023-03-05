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
        if(root==NULL)return {};
        queue<TreeNode*> q;
        q.push(root);
        bool toggle = true;
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> a;
            stack<int> st;
            int s = q.size();
            for(int i = 0; i < s ;i++){
                TreeNode* t = q.front();
                q.pop();
                st.push(t->val);
                a.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(!toggle){
                vector<int> b;
                int i =0;
                while(!st.empty()){
                    b.push_back(st.top());
                    st.pop();
                    i++;
                }
                ans.push_back(b);
            }
            else ans.push_back(a);
            toggle = !toggle;
        }
        return ans;
    }
};