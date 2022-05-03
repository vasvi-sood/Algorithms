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
    vector<vector<int>> levelOrder(TreeNode* root) {
      
       vector<vector<int>> ans;
          if(root==NULL)
              return ans;
        queue<pair<TreeNode*,int>> q;
        int currlevel=0;
        q.push({root,0});
        vector<int> currchild;
        while(!q.empty())
        {
            auto node=q.front().first;
                int val=node->val;
             int level=q.front().second;
            q.pop();
             if(node->left!=NULL)
            {
                q.push({node->left,level+1});
            }
             if(node->right!=NULL)
            {
                q.push({node->right,level+1});
            }
            
            if(currlevel==level)
            {
                currchild.push_back(val);
            }
            else
            {
               ans.push_back(currchild);
                currchild={};
                  currchild.push_back(val);
            }
            
            currlevel=level;
           
        }
        if(!currchild.empty())
         ans.push_back(currchild);
        
        return ans;
    }
};