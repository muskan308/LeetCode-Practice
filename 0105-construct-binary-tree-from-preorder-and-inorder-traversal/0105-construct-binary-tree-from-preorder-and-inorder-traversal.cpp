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
    int preInd=0;
    map<int, int> mp;
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for(int i = 0; i < inorder.size() ; i++){
        mp[inorder[i]] = i;
    }
    return createTree(preorder,inorder,0,inorder.size() - 1);
}
TreeNode* createTree(vector<int>& preorder, vector<int>& inorder,int start, int end){
    if(start > end){
        return NULL;
    }
    int ele = preorder[preInd++];
    TreeNode* node=new TreeNode(ele);
    int pos = mp[ele];
    
    node->left =createTree(preorder, inorder,start,pos-1);
    node->right =createTree(preorder, inorder, pos+1,end);
    return node;
}
};