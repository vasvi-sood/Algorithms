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
    void helper(TreeNode *node, int k, int &pres, int &ans)
    {
        if (node == NULL)
            return;

        helper(node->left, k, pres, ans);

        if (k == pres)
        {
            ans = node->val;
        }
        pres++;
        if (pres <= k)
            helper(node->right, k, pres, ans);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {

        int ans = 0;
        int pres = 1;
        helper(root, k, pres, ans);
        return ans;
    }
};