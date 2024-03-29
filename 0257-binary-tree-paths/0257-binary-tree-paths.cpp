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
    void solve(TreeNode* root,vector<string>&v,string leaf_path){
        if(root==NULL)  return;
        if(root->left==NULL && root->right==NULL){
            leaf_path+=to_string(root->val);
            v.push_back(leaf_path);
            return;
        }
        leaf_path+=(to_string(root->val))+"->";
        solve(root->left,v,leaf_path);
        solve(root->right,v,leaf_path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root,ans,"");
        return ans;
    }
};