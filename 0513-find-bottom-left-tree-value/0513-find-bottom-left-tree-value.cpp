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
    int findBottomLeftValue(TreeNode* root) {
      queue<TreeNode*> q;
        bool a = true;
        int ans = -1;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            if(f==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                a = true;
                continue;
            }
            if(a) 
                ans = f->val;
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
            a = false; 
        }
        return ans;
    }
};