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
    string _minCameraCover(TreeNode *root)

    {
        if (root->left == NULL && root->right == NULL)
            return "Cover Me";
        string lchild = "Covered", rchild = "Covered";
        if (root->left != NULL)
            lchild = _minCameraCover(root->left);
        if (root->right != NULL)
            rchild = _minCameraCover(root->right);
        if (lchild == "Cover Me" || rchild == "Cover Me")
        {
            cameras++;
            return "Has Camera";
        }
        if (lchild == "Has Camera" || rchild == "Has Camera")
        {
            return "Covered";
        }

        // both are covered
        return "Cover Me";
    }
    int cameras = 0;

public:
    int minCameraCover(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        string status = _minCameraCover(root);
        if (status == "Cover Me")
            cameras++;

        return cameras;
    }
};