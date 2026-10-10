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
    stack<TreeNode*>asc , dsc;

    void pushLeft(TreeNode* root){
        while(root != nullptr){
            asc.push(root);
            root = root -> left;
        }
    }

    void pushRight(TreeNode* root){
        while(root != nullptr){
            dsc.push(root);
            root = root->right;
        }
    }

    int getNextsmall(){
        TreeNode* node = asc.top();
        asc.pop();

        pushLeft(node->right);

        return node->val;
    }

    int getNextbig(){
        TreeNode* node = dsc.top();
        dsc.pop();

        pushRight(node->left);
        return node->val;
    }


    //main func
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;

        pushLeft(root);
        pushRight(root);

        int left = getNextsmall();
        int right = getNextbig();

        while(left < right){
            int sum = left + right;

            if(sum == k)return true;
            if(sum < k) left = getNextsmall();
            else right = getNextbig();
        }

        return false;
    }  
};