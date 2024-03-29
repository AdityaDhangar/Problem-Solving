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
    int ans=0;
    void finder(TreeNode* root, int targetSum,long long int c_sum){
        if(!root)return;
        c_sum+=root->val;
        if(c_sum==targetSum)ans++;
        finder(root->left,targetSum,c_sum);
        finder(root->right,targetSum,c_sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        long long int c_sum=0;
        finder(root,targetSum,c_sum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }  
    
};