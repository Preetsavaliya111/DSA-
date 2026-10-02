/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;

    int fun(TreeNode* Node, TreeNode* p, TreeNode* q){
        if(Node == NULL)return 0;

        int left = fun(Node->left , p , q);
        int right = fun(Node->right , p ,q);

        int self = 0;

        if(Node == p || Node == q)self = 1;

        int total = left + right + self;
        if(total == 2  && ans == NULL)
        ans = Node;

        return total;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fun(root , p , q);

        return ans;
    }
};