#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        int maxPathSum(TreeNode* root) 
        {
            int maxSum = INT_MIN;
            maxPathSumHelper(root, maxSum);
            return maxSum;
        }

    private:
        int maxPathSumHelper(TreeNode* node, int& maxSum) 
        {
            if (!node) 
                return 0;

            int left = std::max(0, maxPathSumHelper(node->left, maxSum));
            int right = std::max(0, maxPathSumHelper(node->right, maxSum));

            int currentMax = node->val + left + right;

            maxSum = std::max(maxSum, currentMax);

            return node->val + std::max(left, right);
        }
};

TreeNode* newNode(int val) 
{
    TreeNode* node = new TreeNode(val);
    node->left = node->right = nullptr;
    return node;
}

int main() {

    Solution solution;

    TreeNode* root = newNode(-10);
    root->left = newNode(9);
    root->right = newNode(26);
    root->right->left = newNode(5);
    root->right->right = newNode(17);

    int result = solution.maxPathSum(root);
    std::cout << "Maximum path sum: " << result;

    return 0;
}
