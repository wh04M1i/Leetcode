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
   int maxLevelSum(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int maxLevel = 1;  // Initialize the maximum level to 1
        int maxSum = root->val;  // Initialize the maximum sum to the root value

        std::queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            int currentSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                currentSum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxLevel = level;
            }

            level++;
        }

        return maxLevel;
    }
};