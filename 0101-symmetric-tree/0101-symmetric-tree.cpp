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

    bool fun(TreeNode* r1 , TreeNode* r2){

        if(r1 == NULL && r2 == NULL) return true;
        if(r1 == NULL || r2 == NULL) return false;

        if(r1->val != r2->val)return false;

        bool R1 = fun(r1->left , r2->right);
        bool R2 = fun(r1->right , r2->left);

        if(R1 == true && R2 == true)return true;

        return false;

    }
    bool isSymmetric(TreeNode* root) {
    if(root == NULL)return false;

        return fun(root->left , root->right);
    }
};