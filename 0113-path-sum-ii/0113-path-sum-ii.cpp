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
  void finder(TreeNode* root, int sum, int t, vector<vector<int>>&ans,vector<int>&path){
        if(root==NULL)
            return ;
        sum+=root->val;
        path.push_back(root->val);
        if(sum==t && !root->left && !root->right){
            ans.push_back(path);
        }
        finder(root->left,sum,t,ans,path);
        finder(root->right,sum,t,ans,path);
        sum-=root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>>ans;
        int sum=0;
        vector<int>path;
        finder(root,sum,t,ans,path);
        return ans;
        
    }
};