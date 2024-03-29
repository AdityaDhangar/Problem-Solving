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
    string s, t;
    void traverse(TreeNode* root, int start, int dest, string &a){
        if(!root){
            return;
        }
        if(root ->val == start){
            s = a;
        }
        if(root ->val == dest){
            t = a;
        }
        if(root ->left){
            a.push_back('L');
            
            traverse(root ->left, start, dest, a);
            a.pop_back();
           
        }
        if(root ->right){
            a.push_back('R');
            traverse(root ->right, start, dest, a);
            a.pop_back();
        }
        

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string a= "", b = "";
        traverse(root, startValue, destValue,a);
        string ans="";
        int i = 0, j = 0;
        while(i<s.size() && j<t.size()&& s[i] == t[j]){
            i++;
            j++;
        }
        while(i<s.size()){
            ans += 'U';
            i++;
        }
        ans += t.substr(j);
        return ans;
    }
};