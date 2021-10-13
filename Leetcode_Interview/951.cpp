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
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL)
            return false;
        if (root1->val != root2->val)
            return false;

        int left1 = root1->left ? root1->left->val : INT32_MAX;
        int right1 = root1->right ? root1->right->val : INT32_MAX;
        int left2 = root2->left ? root2->left->val : INT32_MAX;
        int right2 = root2->right ? root2->right->val : INT32_MAX;
        bool ans = true;
        if (left1 == left2 && right1 == right2)
        {
            ans = ans && flipEquiv(root1->left, root2->left);
            // cout<<ans<<" "<<left1<<endl;
            ans = ans && flipEquiv(root1->right, root2->right);
            // cout<<ans<<" "<<right1<<endl;
        }

        else if (left1 == right2 && right1 == left2)
        {
            auto temp = root1->left;
            root1->left = root1->right;
            root1->right = temp;
            ans = ans && flipEquiv(root1->left, root2->left);
            ans = ans && flipEquiv(root1->right, root2->right);
        }
        else
            return false;

        return ans;
    }
};