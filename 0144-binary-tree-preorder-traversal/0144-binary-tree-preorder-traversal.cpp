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

    void func(TreeNode* node , vector<int>&res){
        if(node == NULL){return;}

        res.push_back(node->val);
        func(node->left ,res);
        func(node->right , res);

        return;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        func(root,res);

        return res;
    }
};