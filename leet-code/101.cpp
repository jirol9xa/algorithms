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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return isSubTreeEqual(root->left, root->right);
    }

    bool isSubTreeEqual(TreeNode *first, TreeNode *second) {
        if (!first && !second)
            return true;
        if (!first || !second)
            return false;
        
        return  first->val == second->val && 
                isSubTreeEqual(first->left,  second->right) && 
                isSubTreeEqual(first->right, second->left);
    }
};;
