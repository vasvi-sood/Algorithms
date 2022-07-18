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
class Solution
{
    void helper(int curr, int &ans, TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            ans += curr * 10 + root->val;
        }

        helper(curr * 10 + root->val, ans, root->left);
        helper(curr * 10 + root->val, ans, root->right);
    }
    void helper(string curr, int &ans, TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            curr += root->val + '0';
            ans += stoi(curr);
            return;
        }

        curr += root->val + '0';
        helper(curr, ans, root->left);
        helper(curr, ans, root->right);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        helper(0, ans, root);
        return ans;
    }
};