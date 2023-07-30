#include <stack>
#include <vector>

template <typename T> using vector = std::vector<T>;

template <typename T> using stack = std::stack<T>;

struct TreeNode {
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        vector<int> resVec;

        stack<TreeNode *> nodeStack;
        nodeStack.push(root->right);
        nodeStack.push(root);
        nodeStack.push(root->left);

        while (!nodeStack.empty()) {
            root = nodeStack.top();
            nodeStack.pop();
            if (!root)
                continue;

            if (root->right == nodeStack.top()) {
                resVec.push_back(root->val);
                continue;
            }

            nodeStack.push(root->right);
            nodeStack.push(root);
            nodeStack.push(root->left);
        }

        return resVec;
    }
};
