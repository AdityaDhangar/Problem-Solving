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
    bool finder(TreeNode* root, int t,int sum){
        if(!root)return false;
        sum+=root->val;
        if(sum==t && root->left==NULL && root->right==NULL)
            return true;
        if(finder(root->left,t,sum) || (finder(root->right,t,sum)))
            return true;
        sum-=root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return finder(root,targetSum,sum);
    }
};