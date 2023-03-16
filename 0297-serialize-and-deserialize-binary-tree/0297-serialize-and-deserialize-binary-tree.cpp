/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL){
                str += "#,";
            }else{
                str += (to_string(front->val) + ",");
                q.push(front->left);
                q.push(front->right);
            }
            
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            //for left child of front
            getline(ss, str, ',');
            if(str == "#"){
                front->left = NULL;
            }
            else{
                TreeNode* lchild = new TreeNode(stoi(str));
                q.push(lchild);
                front->left = lchild;
            }

            //right child of front
            getline(ss, str, ',');
             if(str == "#"){
                front->right = NULL;
            }
            else{
                TreeNode* rchild = new TreeNode(stoi(str));
                q.push(rchild);
                front->right = rchild;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));