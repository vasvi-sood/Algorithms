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
   pair<bool,int> child(TreeNode* root)
    {
       
       if(root==NULL)
       return {true,0};

       pair<bool,int> left=child(root->left);
       pair<bool,int> right=child(root->right);
    //    cout<<root->val<<" : \n";
       if(left.first==false || right.first==false || (abs(left.second-right.second)>1))
       {
            // cout<<"here\n";
       return {false,0};
      
       }
       else
       {
        //    cout<<"here2\n";
       return {true,1+max(right.second,left.second)};
       
       }

      
    }
public:
    bool isBalanced(TreeNode* root) {
        pair<bool,int> ans=child(root);
        return ans.first;

    }
};