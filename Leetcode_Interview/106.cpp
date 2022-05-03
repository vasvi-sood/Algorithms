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
int getIndex(vector<int> &arr, int val)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}
class Solution
{
    TreeNode *bTree(vector<int> &inorder, vector<int> &postorder, int ibeg, int iend, int pbeg, int pend)
    {
        if (iend < ibeg)
            return NULL;
        int rval = postorder[pend];
        TreeNode *root = new TreeNode(rval);
        int idx = getIndex(inorder, rval);
        int ibegn = ibeg;
        int iendn = idx - 1;
        int len = iendn - ibegn;
        int pbegn = pbeg;
        int pendn = pbegn + len;
        root->left = bTree(inorder, postorder, ibegn, iendn, pbegn, pendn);
        ibegn = idx + 1;
        iendn = iend;
        len = iendn - ibegn;
        pendn = pend - 1;
        pbegn = pendn - len;
        root->right = bTree(inorder, postorder, ibegn, iendn, pbegn, pendn);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return bTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};