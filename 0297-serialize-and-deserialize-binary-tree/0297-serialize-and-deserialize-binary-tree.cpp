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
    string serialize(TreeNode* root)  {
        if (root == nullptr) return "null,";

        string serializedTree = to_string(root->val) + ",";
        serializedTree += serialize(root->left);
        serializedTree += serialize(root->right);

        return serializedTree;
    }
                                     
    TreeNode* deserializeHelper(queue<string>& nodes) {
        string valStr = nodes.front();
        nodes.pop();

        if (valStr == "null") {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(valStr));
        node->left = deserializeHelper(nodes);
        node->right = deserializeHelper(nodes);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string temp;
        
        while (getline(ss, temp, ',')) {
            nodes.push(temp);
        }

        return deserializeHelper(nodes);
    }
                                    
};
        
  

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));